cmake_minimum_required(VERSION 3.16)
project(violet LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------------------------------
# GTKMM vía pkg-config (cross-platform)
# ---------------------------------------
find_package(PkgConfig REQUIRED)
if (WIN32)
  pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-2.4)
else()
  pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)
endif()
# ---------------------------------------
# GResources
# ---------------------------------------
set(GRESOURCE_XML ${CMAKE_SOURCE_DIR}/resources/violet.gresource.xml)
set(GRESOURCE_C ${CMAKE_BINARY_DIR}/violet_gresource.c)

add_custom_command(
    OUTPUT ${GRESOURCE_C}
    COMMAND glib-compile-resources
        ${GRESOURCE_XML}
        --target=${GRESOURCE_C}
        --generate-source
        --sourcedir=${CMAKE_SOURCE_DIR}/resources
    DEPENDS
        ${GRESOURCE_XML}
        ${CMAKE_SOURCE_DIR}/resources/ui/mainwindow.ui
    VERBATIM
)

add_custom_target(violet_gresource DEPENDS ${GRESOURCE_C})

# ---------------------------------------
# Ejecutable
# ---------------------------------------
add_executable(violet
    src/main.cpp
    src/app/app.cpp
    ${GRESOURCE_C}
)

add_dependencies(violet violet_gresource)

target_include_directories(violet PRIVATE src)
target_link_libraries(violet PRIVATE PkgConfig::GTKMM)

# ---------------------------------------
# Install
# ---------------------------------------
include(GNUInstallDirs)

install(TARGETS violet
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    FILES resources/violet.desktop
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/applications
)

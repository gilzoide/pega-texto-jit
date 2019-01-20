include_directories(${LIBJIT_INCLUDE_DIRS} ${PEGA_TEXTO_INCLUDE_DIRS})
link_libraries(${LIBJIT_LIBRARIES} ${PEGA_TEXTO_LIBRARIES})

# Version check
file(STRINGS "pega-texto-jit.h" _version_line REGEX "PT_JIT_VERSION")
string(REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" PT_JIT_VERSION ${_version_line})
if(NOT PT_JIT_VERSION VERSION_EQUAL ${PROJECT_VERSION})
	message(SEND_ERROR "Version from CMakeLists.txt doesn't match the one in pega-texto-jit.h")
endif()

add_library(pega-texto-jit pega-texto-jit.c)
set_target_properties(pega-texto-jit PROPERTIES
	VERSION "${PROJECT_VERSION}"
	SOVERSION "${PROJECT_SOVERSION}")

if(COMPILE_EXAMPLE)
	add_executable(test main.c)
	target_link_libraries(test $<TARGET_LINKER_FILE:pega-texto-jit>)
endif()

if(NOT WIN32 AND UNIX AND BUILD_SHARED_LIBS AND LINK_SONAME_FILE)
	if(APPLE)
		set(lib-ext dylib)
	else()
		set(lib-ext so)
	endif()
	set(link-name "libpega-texto-jit${PROJECT_VERSION_MAJOR}.${lib-ext}")
	add_custom_command(TARGET pega-texto-jit POST_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink $<TARGET_SONAME_FILE_NAME:pega-texto-jit> ${link-name})
	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${link-name} DESTINATION lib)
endif()

install(TARGETS pega-texto-jit
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)
install(FILES "pega-texto-jit.h" DESTINATION include)

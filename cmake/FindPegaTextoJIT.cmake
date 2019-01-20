# FindPegaTextoJIT
# -------------------
# Locate pega-texto-jit library. This module defines:
#
#   PEGA_TEXTO_JIT_FOUND         - true if pega-texto-jit library was found
#   PEGA_TEXTO_JIT_LIBRARIES     - pega-texto-jit library
#   PEGA_TEXTO_JIT_INCLUDE_DIRS  - where to find pega-texto-jit.h
#   PEGA_TEXTO_JIT_VERSION       - the version of pega-texto-jit found

find_path(PEGA_TEXTO_JIT_INCLUDE_DIRS
	pega-texto-jit.h
	PATH_SUFFIXES pega-texto-jit/include)

find_library(PEGA_TEXTO_JIT_LIBRARIES
	NAMES pega-texto-jit pega-texto-jit0
	PATH_SUFFIXES pega-texto-jit/lib)

# find library version in header file
if(PEGA_TEXTO_JIT_INCLUDE_DIRS)
	file(STRINGS "${PEGA_TEXTO_JIT_INCLUDE_DIRS}/pega-texto-jit.h" _version_line REGEX "PT_JIT_VERSION")
	string(REGEX MATCH "[0-9]+\\.[0-9]+\\.[0-9]+" PEGA_TEXTO_JIT_VERSION ${_version_line})
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PegaTextoJIT
	REQUIRED_VARS PEGA_TEXTO_JIT_LIBRARIES PEGA_TEXTO_JIT_INCLUDE_DIRS
	VERSION_VAR PEGA_TEXTO_JIT_VERSION)

mark_as_advanced(PEGA_TEXTO_JIT_LIBRARIES PEGA_TEXTO_JIT_INCLUDE_DIRS)

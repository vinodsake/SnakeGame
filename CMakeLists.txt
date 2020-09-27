cmake_minimum_required(VERSION 3.10)

project(${project})

find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

file(GLOB SUBDIR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(SUBDIRS ${SUBDIR})
	if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIRS})
		if(${SUBDIRS} STREQUAL "_build" OR ${SUBDIRS} STREQUAL ".git")
		else()
			add_subdirectory(${SUBDIRS})
		endif()	
	endif()
endforeach()

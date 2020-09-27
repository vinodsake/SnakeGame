set( LINK_LIBS  
	${SDL2_LIBRARIES}
	${SDL2_LIBRARIES}_image
	${SDL2_LIBRARIES}_ttf 
	${SDL2_LIBRARIES}_mixer
	${PROJECT_NAME}::sdl
)

set( INCLUDES
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_HOME_DIRECTORY}/sdl/include
	${SDL2_INCLUDE_DIRS} 
 )

get_filename_component(TARGET_LIB ${CMAKE_CURRENT_SOURCE_DIR} NAME)
file(GLOB TARGET_SRCS "*.h" "*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DMYPROJECT=${project})
add_executable(${TARGET_LIB} ${TARGET_SRCS})
add_executable(${PROJECT_NAME}::${TARGET_LIB} ALIAS ${TARGET_LIB})
target_include_directories(${TARGET_LIB} PUBLIC ${INCLUDES})
target_link_libraries(${TARGET_LIB} ${LINK_LIBS})


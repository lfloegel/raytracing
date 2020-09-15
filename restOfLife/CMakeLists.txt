cmake_minimum_required(VERSION 3.0.0)
project(inOneWeekend VERSION 0.1.0 LANGUAGES CXX)

set ( CMAKE_CXX_STANDARD 11 ) 

set ( SOURCE_ONE_WEEKEND 
  rtweekend.h
  camera.h
  ray.h
  vec3.h
  hittable.h
  hittable_list.h
  material.h
  sphere.h
  main.cpp
)

set ( SOURCE_NEXT_WEEK
  rtweekend.h
  camera.h
  ray.h
  vec3.h
  aabb.h
  external/stb_image.h
  perlin.h
  rtw_stb_image.h
  texture.h
  aarect.h
  box.h
  bvh.h
  constant_medium.h
  hittable.h
  hittable_list.h
  material.h
  moving_sphere.h
  sphere.h
  main.cpp
)

set ( SOURCE_REST_OF_YOUR_LIFE
  rtweekend.h
  camera.h
  ray.h
  vec3.h
  aabb.h
  external/stb_image.h
  perlin.h
  rtw_stb_image.h
  texture.h
  aarect.h
  box.h
  bvh.h
  hittable.h
  hittable_list.h
  material.h
  sphere.h
  main.cpp
)

include(CTest)
enable_testing()

add_executable(inOneWeekend ${SOURCE_ONE_WEEKEND})
add_executable(theNextWeek ${SOURCE_NEXT_WEEK})
add_executable(theRestOfYourLife ${SOURCE_REST_OF_YOUR_LIFE})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

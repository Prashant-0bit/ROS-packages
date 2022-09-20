cmake_minimum_required(VERSION 3.0.2)
project(tutorial)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   StringWithHeader.msg
)


## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES   
   std_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tutorial
   CATKIN_DEPENDS message_runtime
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(${catkin_INCLUDE_DIRS})


add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker ${catkin_EXPORTED_TARGETS})


add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener ${catkin_EXPORTED_TARGETS})
#############
## Install ##
#############


#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_tutorial.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

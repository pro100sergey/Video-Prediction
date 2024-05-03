project(main CXX)

find_package(userver REQUIRED COMPONENTS core)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} userver::core)

userver_testsuite_add_simple()

cmake_minimum_required(VERSION 3.5) # Обновлено до 3.5 для устранения предупреждения о дефектности

project(Example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG HEAD
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Указываем исходные файлы для исполняемого файла test_all
add_executable(test_all tests/test_foo.cpp Point.cpp Edge.cpp Graph.cpp Parser.cpp)

# Связываем исполняемый файл с библиотекой Google Test
# target_link_libraries(test_all PRIVATE GTest::gtest_main)

# Добавляем тестовый случай
# add_test(NAME test_all COMMAND test_all)

# Создаем исполняемый файл для основной логики приложения
add_executable(Nach main1.cpp Point.cpp Edge.cpp Graph.cpp Parser.cpp)
add_test(NAME MyTest COMMAND test_all)

# Связываем исполняемый файл с библиотекой Google Test
target_link_libraries(Nach PRIVATE GTest::gtest_main)
target_link_libraries(test_all PRIVATE GTest::gtest_main)

# Если у вас есть дополнительные зависимости, например, библиотеки, которые нужно связать с Example, добавьте их здесь
# target_link_libraries(Example PRIVATE <ваш_зависимый_код>)

# 添加可执行文件目标
add_executable(car_test car_main.cpp car.cpp) 

# 设置可执行文件的输出目录（可选）
set_target_properties(car_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)

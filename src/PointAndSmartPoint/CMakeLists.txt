#添加可执行文件目标
add_executable(pointers pointers.cpp)

#设置可执行文件的输出目录(可选)
set_target_properties(pointers PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)

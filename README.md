# Valgrind Exercise

## Standard install via command-line
```bash
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

## To run the Valgrind after build above

```bash
# Use below command to check valgrind output for different memory errors and unintialization errors
valgrind --leak-check=full --track-origins=yes -s ./app/shell-app 

```
The above command can also be used once the errors has been corrected and the output is rebuild

### Bugs Found:
1. In the main.cpp, a unintialized variable is present.
2. In the Analog Sensor.cpp a vector is initialized and then allocated dynamically on heap. This is not required to calculate the sum. So, the vector is initialized back to stack

### Extra Credit Answer
1. In the current scenario, valgrind will detect the two bugs when the executable is linked dynamically. But, if the executable is static, valgrind will detect many additional memory related errors due to many libraries in the shell-app and cmake build of this project are dynamic. When you statically link libraries, the memory management behavior of those libraries becomes part of your program's build such as cmake in current project. Valgrind might not differentiate between memory allocated by your program and memory allocated by these libraries. This can lead to potential false negatives (missing actual issues).

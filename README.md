# Hello Window Template MacOS

This template will give you the necessary steps to install, build, debug and run your C++ project with SDL2. If you want to know how does this template works, read the overview installation. If you just want to start coding, jump to the Step-by-step.

### **References:**

Independentpixels. (2021, October 17). An SDL2 starter project for Mac and VSCode [GitHub repository]. GitHub. https://github.com/independentpixels/sdl2-starter

Independent Pixels. (2021, May 22). Soft robotic gripper for jellyfish [Video]. YouTube. https://www.youtube.com/watch?v=guRoWTYfxMs

### Dependencies:

This template is meant to work with in following environment:

- MacOS
- Visual Studio Code
- VS code C++ Extention: `ms-vscode.cpptools` and `ms-vscode.cpptools-extension-pack`
- brew
- CMake
- g++ compiler (Xcode)

## Overview

We going to use [brew](https://brew.sh/) to install [SDL2](https://formulae.brew.sh/formula/sdl2) globally on the MAC. Once we do this, a set of soft-links defined in this repo are going to point to the location where of the SLD2 header files are located.

We use brew because is the fastest and easiest way to get the source SDL2 source code, without tinkering with the libraries in our project.

***What is a soft link?** Symbolic linking, symlink or soft link, is a mechanism in operating systems that enables us to create a special type of file that serves as a pointer to another file or directory. Instead of containing actual data, a symbolic link contains the path of the target file or directory.

***How to create a soft-link?** the command **`ln -s /path ./my_project/path`** creates a symbolic link from the source file or directory located at **`/path`** to the destination path **`./my_project/path`**. This allows you to access the contents of **`/path`** through the symbolic link located at **`./another/path`**.

```bash
❯ ln -s /opt/homebrew/Cellar/sdl2/2.30.1/include/SDL2 ./include/SDL2

./include
	└── SDL2 -> /opt/homebrew/Cellar/sdl2/2.30.1/include/SDL2
```

*To visualize the folder structure in a “tree” visual structure use `brew install tree`

## Directory content

You can see the three soft links and the `main.cpp` file.

Please notice that the directory .`vsode` contains custom `.json` files written by Independentpixels to run the debug process. 

```jsx
/b-sdl_cmake_hello_window
├── .vscode
│		├── launch.json
│		├── settings.json
│		└── tasks.json
├── LICENSE
├── Makefile
├── README.md
├── build
│   └── debug
├── include
│   ├── SDL2 -> /opt/homebrew/Cellar/sdl2/2.30.1/include/SDL2
│   └── SLD2_image -> /opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2
├── lib
│   └── SDL2_image -> /opt/homebrew/Cellar/sdl2_image/2.8.2_1/lib
└── src
    └── main.cpp
```

## Step-by-step setup

1. Install [brew](https://brew.sh/) if you do not have already
2. Install [CMake](https://formulae.brew.sh/formula/cmake) using brew,  if you do not have already
3. With brew installed, install sdl2 and sdl2_image
    
    ```bash
    brew install sdl2 sdl2_image
    ```
    
4. Clone this repo on your Mac.
5. Change directory into the project
    
    ```jsx
    cd .PATH/b-sdl_cmake_hello_window
    ```
    
6. Inside `./b-sdl_cmake_hello_window` run make to compile, link, name and execute the program.
    
    ```bash
    make
    ```
    
    You should see this output
    
    ```bash
    g++ -std=c++20 -Wall -O0 -g -lsdl2 -Iinclude -Llib src/main.cpp -o build/debug/game && ./build/debug/game
    Hello Window! 
    SDL_Init succeeded 
    ```
The following black window with a white point in the middle will appear:
<img src="https://github.com/DavidGiraldoCode/b-sdl_cmake_hello_window/blob/main/hello_window_outcome.png?raw=true" alt="Alt text" width="80%">

## Luckily, you are now ready to build your own game engine 👾.

### But, before you start…

If you are using the VSCode debugger, you will probably want to remove the command that automatically executes the program after compilation. In that case, go into the Makefile, and in the last line remove `&& ./$(BUILD_DIR)/$(OBJ_NAME)`

```cpp
all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) && ./$(BUILD_DIR)/$(OBJ_NAME)
```

It should look like this

```cpp
all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
```
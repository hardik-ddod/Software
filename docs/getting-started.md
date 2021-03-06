# Software Setup

## Table Of Contents
<!-- 
    NOTE: when creating or re-creating a table of contents like this, you can
    save a LOT of time by using this tool: 
    https://github.com/ekalinin/github-markdown-toc
-->
* [Table Of Contents](#table-of-contents)
* [Introduction](#introduction)
* [Installation and Setup](#installation-and-setup)
* [Operating Systems](#operating-systems)
* [Getting the Code](#getting-the-code)
* [Running the setup scripts](#running-the-setup-scripts)
   * [Installing Software Dependencies](#installing-software-dependencies)
   * [Installing Firmware Dependencies](#installing-firmware-dependencies)
   * [Setting Up USB Permissions](#setting-up-usb-permissions)
   * [Installing CLion](#installing-clion)
      * [Getting your Student License](#getting-your-student-license)
      * [Installing CLion](#installing-clion-1)
* [Building and Running the Code](#building-and-running-the-code)
* [Debugging](#debugging)
* [Profiling](#profiling)
* [Flashing and Debugging A STM32F4 MCU](#flashing-and-debugging-a-stm32f4-mcu)
* [Flashing and Debugging A STM32H7 MCU](#flashing-and-debugging-a-stm32h7-mcu)

## Introduction
These instructions assume that you have the following accounts setup:
- [Github](https://github.com/login)
- [Slack](https://thunderbots.slack.com/)

These instructions assume you have a basic understanding of Linux and the command-line. There are many great tutorials online, such as [LinuxCommand](http://linuxcommand.org/). The most important things you'll need to know are how to move around the filesystem, and how to run programs or scripts.

## Installation and Setup

## Operating Systems

We currently only support Linux, specifically Ubuntu 18.04 LTS. You are welcome to use a different version or distribution of Linux, but may need to make some tweaks in order for things to work.

You can use Ubuntu 18.04 LTS inside Windows through Windows Subsystem for Linux, by following [this guide](./getting-started-wsl.md). **Running and developing Thunderbots on Windows is experimental and not officially supported.**

## Getting the Code

1. Open a new terminal
2. Install git by running `sudo apt-get install git`
3. Go to the [software repository](https://github.com/UBC-Thunderbots/Software)
4. Click the `Fork` button in the top-right to fork the repository ([click here to learn about Forks](https://help.github.com/en/articles/fork-a-repo))
   1. Click on your user when prompted
   2. You should be automatically redirected to your new fork
5. Clone your fork of the repository (you can put it wherever you want)
   1.  Eg. `git clone https://github.com/<your-username>/Software.git`
      1. You can find this link under the green `Clone or Download` button on the main page of the Software repository
   2. We recommend cloning with SSH if you don't like typing your username and password all the time. Instructions can be found [here](https://help.github.com/articles/connecting-to-github-with-ssh/).
6. Set up your git remotes ([what is a remote and how does it work?](https://git-scm.com/book/en/v2/Git-Basics-Working-with-Remotes))
   1. You should have a remote named `origin` that points to your fork of the repository. Git will have set this up automatically when you cloned your fork in the previous step.
   2. You will need to add a second remote, named `upstream`, that points to our main Software repository, which is where you created your fork from. (**Note:** This is _not_ your fork)
      1. Open a terminal and navigate to the folder you cloned (your fork): `cd path/to/the/repository/Software`
      2. Navigate to our main Software repository in your browser and copy the url from the "Clone or Download" button. Copy the HTTPS url if you originally cloned with HTTPS, and use the SSH url if you previously cloned with SSH
      3. From your terminal, add the new remote by running `git remote add upstream <the url>` (without the angle brackets)
         1. Eg. `git remote add upstream https://github.com/UBC-Thunderbots/Software.git`
      4. That's it. If you want to double check your remotes are set up correctly, run `git remote -v` from your terminal (at the base of the repository folder again). You should see two entries: `origin` with the url for your fork of the repository, and `upstream` with the url for the main repository

*See our [workflow document](workflow.md) for how to use git to make branches, submit Pull Requests, and track issues*

## Running the setup scripts

We have several setup scripts to help you easily install the necessary dependencies in order to build and run our code. You will want to run the following scripts, which can all be found in `Software/environment_setup`

### Installing Software Dependencies

* Inside a terminal, navigate to the environment_setup folder. Eg. `cd path/to/the/repository/Software/environment_setup`
* Run `./setup_software.sh`
  * You will be prompted for your admin password
  * This script will install everything necessary in order to build and run our main `AI` software 

### Installing Firmware Dependencies

* Inside a terminal, navigate to the environment_setup folder. Eg. `cd path/to/the/repository/Software/environment_setup`
* Run `./setup_firmware.sh`
  * You will be prompted for your admin password
  * This script will install everything necessary in order to build and run our robot firmware

### Setting Up USB Permissions

* inside a terminal, navigate to the `environment_setup` folder. Eg. `cd path/to/the/repository/Software/environment_setup` 
  * Run `./setup_udev_rules.sh`
    * You will be prompted for your admin password
    * This script will set up the USB permissions required in order to use our radio/wifi dongle

### Installing CLion

CLion is our main IDE for editing our C/C++ code. It is designed to work with our build system, `bazel`, and has all the great features of an IDE such as code completion, syntax highlighting etc. We **strongly** recommend installing CLion and using it for development.

#### Getting your Student License

CLion is free for students, and you can use your UBC alumni email address to create a student account. If you already have a student account with JetBrains, you can skip this step.

1. If you haven't done so already, setup your UBC alumni email account [here](https://id.ubc.ca/).
2. Using your UBC email account, get a JetBrains education account [here](https://www.jetbrains.com/shop/eform/students).
   1. _JetBrains will send an initial email to confirm the UBC email you inputted. Once you have confirmed, another email will be sent to activate your new education account. You will use this account to set up CLion later on._

#### Installing CLion

* Inside a terminal, navigate to the environment_setup folder. Eg. `cd path/to/the/repository/Software/environment_setup`
* Run `./install_clion.sh` (* **DO NOT** download CLion yourself unless you know what you're doing. The `install_clion.sh` script will grab the correct version of CLion and the Bazel plugin to ensure everything is compatible *).
* When you run CLion for the first time you will be prompted to enter your JetBrains account or License credentials. Use your student account.

## Building and Running the Code

### From the command-line

1. Navigate to the root of this repository (wherever you have it cloned on your computer)
2. Navigate to `src`.
3. Build a specific target for running (for example): `bazel build //software/geom:angle_test`
4. Run a specific target by running (for example): `bazel run //software/geom:angle_test`
5. Run a specific *test* by running (for example): `bazel test //software/geom:angle_test`
6. Build everything by running `bazel build //...`
7. Run all the tests by running `bazel test //...`
*See the bazel [command-line docs](https://docs.bazel.build/versions/master/command-line-reference.html) for more info.*

### With CLion

First we need to setup CLion
1. Open CLion
2. Select `Import Bazel Project`
3. Set `Workspace` to wherever you cloned the repository + `/src`. So if I cloned the repo to `/home/my_username/Downloads/Software`, my workspace would be `/home/my_username/Downloads/Software/src`.
4. Select `Import project view file`, and select the file `.bazelproject` (which will be under the `src` folder)
5. Click `Next`
6. Change the Project Name to whatever you want. Leave everything else as it is ("Use shared project view file" should be selected).
7. Click `Finish` and you're good to go! Give CLion some time to find everything in your repo.


Now that you're setup, if you can run it on the command line, you can run it in clion. There are two main ways of doing so.
1. Open any `BUILD` file and right clight in a `cc_library()` call. This will give you the option to `Run` or `Debug` that specific target. Try it by opening `Software/src/software/geom/BUILD` and right-clicking on the `cc_library` for `angle_test`!
2. Add a custom build configuration (more powerful, so make sure you understand this!)
    1. Select `Add Configuration` from the drop-down in the top-right of CLion
    2. Click on `+`, choose `Bazel Command`.
    3. For `Target Expression`, you can put anything that comes after a `build`, `run`, `test`, etc. call on the command line. For example: `//software/geom:angle_test`.
    4. For `Bazel Command` you can put any bazel command, like `build`, `run`, `test`, etc.
    5. Click `Ok`, then there should be a green arrow in the top right corner by the drop-down menu. Click it and the test will run!

### Running our AI, Simulator or Robot Diagnostics

1. Open your terminal and run `ifconfig`.
2. Pick the network interface you would like to use:
    1. If you are running things locally, you can pick any interface that is not `lo`
    2. If you would like to communicate with robots on the network, make sure to select the interface that is connected to the same network as the robots.
3. Run our AI: `bazel run //software:full_system -- --interface=[interface_here] --backend=WifiBackend`
    - This will launch the Visualizer, which displays what the AI is currently "seeing" and allows us to interact with the AI through the dynamic parameters.
    - The field should be empty, as we are currently not receiving SSL Vision packets.
4. Run our Simulator: `bazel run //software/simulation:standalone_simulator_main -- --interface=[interface_here]`
    - The Simulator runs our firmware and Box2D (a physics engine) to simulate how our robots would behave on the field.
    - The Simulator outputs SSL Vision packets, which contain position information of all robots and the ball.
    - Our AI can now "see" the robots, and they should be displayed on the Visualizer.
    - You can use ctrl-click to move the ball around in the Simulator, and try changing the Play Override on the Visualizer to see the robots move!
5. Run Robot Diagnostics: `bazel run //software/gui/robot_diagnostics:robot_diagnostics_main -- --interface=[interface_here] --backend=WifiBackend`
    - The Mechanical and Electrical sub-teams use Robot Diagnostics to test specific parts of the Robot.


## Debugging
Debugging from the command line is certainly possible, but debugging in a full IDE is *really* nice (plz trust us). 

### With CLion
Debugging in CLion is as simple as running the above instructions for building CLion, but clicking the little green bug in the top right corner instead of the little green arrow!

### From The Command line
`bazel run -c dbg --run_under="gdb" //some/target:here` will run the target in `gdb`. Please see (here)[https://www.cs.cmu.edu/~gilpin/tutorial/] for a tutorial on how to use `gdb` if you're not familiar with it.


## Profiling 
Unfortunately profiling for Bazel targets is not supported in CLion at this time. Hence the only way is via command line. Use the following command:
```
bazel run -c dbg --run_under="valgrind --tool=callgrind --callgrind-out-file=/ABSOLUTE/PATH/TO/profile.callgrind" //target/to:run

// Example
bazel run -c dbg --run_under="valgrind --tool=callgrind --callgrind-out-file=/tmp/profile.callgrind" //software/geom:angle_test
```
This will output the file at the _absolute_ path given via the `--callgrind-out-file` argument. This file can then be viewed using `kcachegrind` (example: `kcachegrind /tmp/profile.callgrind`), giving lots of useful information about where time is being spent in the code.

## Flashing And Debugging A STM32F4 MCU
1. Make sure you've followed [Installing Firmware Dependencies](#installing-firmware-dependencies), and have a STM32F4 based main board or radio dongle plugged into your computer. Do not plug both the dongle and the robot at the same time!
2. Make sure the robot is elevated, with the wheels not touching any surface to avoid experimental firmware causing accidental damage.
3. From the `src` folder, to flash the radio dongle, run `bazel run --cpu=stm32f4 //firmware/tools:legacy_flash_firmware radio_dongle`. Replace `radio_dongle`, with `robot` to flash the robot.
4. For the robot, make sure the robot is in bootloader mode (BL switch on the piano keys is down), and push the power switch away from the dribbler (i.e towards the back of the robot) and hold it there before running the command. The dongle can be simply be plugged in with no additional action.
5. There should be a progress bar indicating the flashing progress, hold the switch back until the process finishes.
6. When the process is finished, release the power switch, push the BL switch back up, and the robot now has been flashed!
7. To see print outs from the robot, run `sudo cat /dev/ttyACM0`. If `ttyACM0` isn't the right device, run `ls /dev/tty*` with the robot disconnected, and again with the robot connected, and replace `ttyACM0` with the new device that has been added. The radio dongle does not have this feature.

## Flashing And Debugging A STM32H7 MCU
1. Make sure you've followed [Installing Firmware Dependencies](#installing-firmware-dependencies), and have a [NUCLEO-H743ZI](https://www.st.com/en/evaluation-tools/nucleo-h743zi.html) plugged into your computer.
2. From the `src` folder, run `bazel run --cpu=stm32h7 --compilation_mode=dbg //firmware_new/tools:debug_firmware_on_arm_board`. We specify `--cpu=stm32h7` because we want to compile code for the stm32h7 MCU (rather then a `x86_64` processor like you have in your computer), and `--compilation_mode=dbg` in order to build in the debug symbols required so you can step through the code and see what's going on. You'll be given a list of elf files to choose from.
3. Assuming you choose 0 from the list in step (2), run `bazel run --cpu=stm32h7 --compilation_mode=dbg //firmware_new/tools:debug_firmware_on_arm_board 0`. This will load the `.elf` file associated with (0) to the nucleo and put you into a gdb prompt.
4. At this point you should be in a gdb window. Take a look at [this tutorial](https://www.cprogramming.com/gdb.html) for some basics.

## Working with CubeMX to regenerate code
1. Make sure you've followed [Installing Firmware Dependencies](#installing-firmware-dependencies)
2. To regenerate code from the `.ioc` file, run `bazel run //firmware_new/tools:cubemx_regen path/to/directory/with/.ioc`. The directory that is passed in as an argument must only contain 1 ioc file, which will be used to generate code into the same directory.

To make sure we are all using the same cube version, run `STM32CubeMX` when editing the `.ioc` file.

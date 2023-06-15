# CType-Ev3
Programming Ev3 using C

This will use compiled files to run programs on the ev3. This allows for much better performance and eliminates all the shortcomings of python.

"Soccer New" is the current running soccer code, meant for the holonomic robot. The code is c++ with the C like ev3 api. The code should only allocate to the stack, and should minimize the size of it's types as much as possible. It's meant for maximum performance, so there needs to be a lot of consideration on the design and implementation. Possible psuedocode inclusion for the algorithms used.

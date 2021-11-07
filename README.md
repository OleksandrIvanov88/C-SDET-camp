# Binary Maze

This application provides the function that takes as an input a two-dimensional square matrix(std::array) consisting of 0 and 1.The input matrix is the maze where 1 means that the route is available while 0 means that it is not. Diagonal route paths are not allowed, only horizontal and vertical. The function output is True or False depending on the fact if there is a way from the top left corner of the matrix to the lowest right one.

### Build and run
- mkdir build && cd build
- cmake ../
- make 
- ./maze-tests  - Run tests
- ./maze        - Run demo


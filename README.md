# Make-Lib
 This is a repository containing the code for a basic data-structure and graph library.
##### We need just a terminal for installing the library.

### Steps to install
- First head over to the linux terminal.
- Then move to the directory where the folders `data_structures`, `graph` and `application` are present.
- Now type the following commands one by one,
    - `make -f ./data_structures/makefile.basic install`
    - `make -f ./graph/makefile.graph install`
    - `make -f ./application/makefile install`
- By now everything should have worked just fine.
- If you want to do something else, then you might check out the info-logs that get printed after running each command.

### Steps to Uninstall
- Head over to the directory where the the folders `data_structures`, `graph` and `application` are present and open the terminal.
- Now type the following commands one by one,
    - `make -f ./data_structures/makefile.basic uninstall`
    - `make -f ./graph/makefile.graph uninstall`

### Steps to clean the object files
- Head over to the directory where the the folders data_structures, graph and application are present and open the terminal.
- Now type the following commands one by one,
    - `make -f ./data_structures/makefile.basic clean`
    - `make -f ./graph/makefile.graph clean`
    
### For testing the library (in order to ensure correct implementation)
- Head over to the application directory.
- Create a text file and type the input of a graph in it. For the input format check the `README` file of the `application` directory.
- After this run the executable and type in the file name (along with extension) of the text file you created.
- You will see the DFS, BFS and MST of the graph printed on the console.

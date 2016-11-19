#CS100 Assignment 3 - rshell

###Elijah Cain and Aaron Ha

## Summary and Requirements
This is a c++ program that acts as a BASH Shell. It has the capability to execute all bash commands
found in bin so it cannot do commands such as ```cd```. It also has the capabilty of handling mutliple commands using 
the BASH connectors ```||```, ```&&``` and ```;```. If the user enters `#` it will act as a comment and everything after it will be ignored. These connectors will determing if the command is executed based off
of the previous commands success. The program will exit when the user hits "exit". The added functionality includes precedence and testing 
of directories and files. 

##Developer Tasks 
Aaron was tasked with parsing the user input and storing it into a container, and Elijah was responsible for handling execution as well as general program organization. We developed entirely on c9.io and cloned the repo into the service so that we could push updates onto our remote repo. This is the reason why only one person commited to the repository. 

##Strategy
A composite pattern was used a with one leaf node and one composite node. A indivdual command was encapsualted in a `Token` leaf node and the `TokenComposite` node has a container of `Token` nodes. The base class has a `execute` function that the children implemented. `Token`'s `execute()` would have the system calls `fork()` and `execvp()` to execute the indivdual programs. The `TokenComposite`'s `execute()` would iterate through the `Token` objects in it's container and call `execute` on the leaf nodes. The `Parser` class was responsible for parsing the user input and populating the `Token` objects and `TokenComposite` container.  

For assignment 3, Aaron handled parsing of parenthesis and brackets. He handled any other parsing that needed to be done. I handled the 
functionality and logic of the test and precedence. To handle test, we simply created a new function. To handle precadence we added a `vector<Token*>` member variable to the `Token` class. When a parenthesis is detected, the vector is populated with `Token*` objects. This created a tree that will be iterated through in our `TokenComposite` execute function. 
## Bugs
The command `help` continues to not work in our program. We believe this is because `help` is not a built in function and thus is not handled by `execvp`. 

When running the scripts the script would sometimes go under an infinite loop (I believe this is because we didn't call exit, aside from exit test cases)

Comparison between ints and size_types would cause occasional parse bugs. 

GNU GENERAL PUBLIC LICENSE

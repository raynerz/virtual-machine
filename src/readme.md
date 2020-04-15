#Virtual Machine Implementation

From the tutorial on this page: https://blog.felixangell.com/virtual-machine-in-c

Implentation process:

```
1. We implemented the instruction set, these are the operations that we can do with our virtual machine
2. We created a fetch function to fetch the instructions on our program using an instruction pointer.
3. We created a evaluation function that defines what should happen every time we call a instruction from our set.
4. We created a stack using an array and a stack pointer. 
5. We used a loop to run our program in our main method, incrementing the pointer on the program with every iteration on the loop
```

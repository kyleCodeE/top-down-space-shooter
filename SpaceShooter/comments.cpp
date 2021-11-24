// Comments for COP 3003 //

/*

1.  Design and implement a class.

        Include a comment in which you compare and contrast the procedural/functional approach and the object-oriented approach
        /*
        * Most of these classes are used multiple times. If not, at least the methods within them are.
        * If I were to take a procedural approach, I'd be writing the same things over and over again,
        * and making any changes would be much more difficult because I would need to make that change
        * in several places.
        * Using the OOP approach, I can have my classes organized in a way that allows for easy reuse and change.
        * /

        At least one class in a header file with non-trivial methods implemented in a cpp file
        // Player.h and Player.cpp

        Overload a constructor
        // Player.h line 26
        // Player.cpp line 68
        // I see now that I misread this and provided an overloaded operator. OOP[s]

        Utilize an initialization list
        // Best ex. in Entity.
        // All .h files


2.  Use subclassing to design simple class hierarchies that allow code to be reused for distinct subclasses.

        Include comments describing the visibility inheritance model
        // Entity.h

3.  Correctly reason about control flow in a program using dynamic dispatch.

4.  Explain the relationship between object-oriented inheritance (code-sharing and overriding) and 
    subtyping (the idea of a subtype being usable in a context that expects the supertype).

        // Object-oriented inheritance includes the idea that a subclass contains everything 
        // that its superclass does, because it is a version of that superclass. For example, 
        // one of my planned functions would be deleting entities that collide. The function 
        // parameters would ask for an Entity object, but would work with any of the current
        // classes that I have, as they are all subclasses of Entity.

6.  Use object-oriented encapsulation mechanisms such as interfaces and private members.

7.  Define and use iterators and other operations on aggregates, including operations that take 
    functions as arguments.

8.  Follow best practices for style and readability

9.  Follow best practices for documentation

        Include class diagrams for all classes in Readme

*/
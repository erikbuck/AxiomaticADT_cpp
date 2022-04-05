//
//  main.cpp
//  CppAxiomsExample
//
//  Created by Erik M. Buck on 3/29/22.
//

#include "List.h"
#include <iostream>

/** \defgroup StackADT ADT Stack Algebraic Specification
@{
# Stack Axioms

## CANONICAL CONSTRUCTORS

- stack() : -> Stack
- push() : Stack, X -> Stack

## OBSERVERS

- pop() : Stack -> Stack
- top() : Stack -> X or Error
- size() : Stack -> Natural
- equal() : Stack, Stack -> Boolean
**/

////////////////////////////////////////////////////////////////////////////////
// ADT Stack Constructors
////////////////////////////////////////////////////////////////////////////////

/** Stack is implemented as a List **/
typedef List Stack;

/** 
- CONSTRUCTOR
- CONTRACT: stack() : -> Stack 
- PURPOSE:  create new empty stack
\anchor AXIOMStack0 \axiom stack(): size(stack()) = 0
\ref AXIOMTStack0 "Test"
**/
Stack stack() { return Stack {}; }

/** 
- CONSTRUCTOR
- CONTRACT: push(S, X) -> Stack : For all S in Stack, push(S, X) -> Stack 
- PURPOSE:  create new stack formed from Stack, S, extended with a new element, X, in the top position

\anchor AXIOMPush0 \axiom push(): For all S in Stack and X, size(push(S, X)) > 0 
\ref AXIOMTPush0 "Test"

\anchor AXIOMPush1 \axiom push(): For all S in Stack, pop(push(S, X)) -> S ; push() undone via pop() 
\ref AXIOMTPush1 "Test"

\anchor AXIOMPush2 \axiom push(): For all S in Stack, equal(push(S, X), S) -> False 
\ref AXIOMTPush2 "Test"

\anchor AXIOMPush3 \axiom push(): For all S in Stack, top(push(S, X)) -> X ; item pushed is on top 
\ref AXIOMTPush3 "Test"

\anchor AXIOMPush4 \axiom push(): For all S in Stack, top(push(push(S, X), X1) -> X1 ; order matters 
\ref AXIOMTPush4 "Test"
**/
Stack push(const Stack& s, int x) { return append(s, x); }

////////////////////////////////////////////////////////////////////////////////
// ADT Stack Observers
////////////////////////////////////////////////////////////////////////////////

/** 
- OBSERVER
- CONTRACT: pop() : Stack -> Stack
- PURPOSE:  remove top item (if any) from Stack 

\anchor AXIOMPop0 \axiom pop(): pop(stack()) -> Stack 
\ref AXIOMTPop0 "Test"

\anchor AXIOMPop1 \axiom pop(): For all S in Stack, pop(push(S, X)) -> S 
\ref AXIOMTPop1 "Test"
**/
Stack pop(const Stack& s)
{
    if (Stack {} == s) {
        return s;
    } else {
        return rest(s);
    }
}

/** 
- OBSERVER
- CONTRACT: top() : Stack -> X or Error
- PURPOSE:  return the top item (if there is one) from Stack or Error 

\anchor AXIOMTop0 \axiom top(): top(stack()) -> Error
\ref AXIOMTTop0 "Test"

\anchor AXIOMTop1 \axiom top(): For all S in Stack, top(push(S, X) -> X)
\ref AXIOMTTop1 "Test"
**/
int top(const Stack& s)
{
    if (Stack {} == s) {
        throw std::runtime_error("error");
    } else {
        return first(s);
    }
}

/**
- OBSERVER
- CONTRACT: size() : Stack -> Natural
- PURPOSE:  return the number of item in a Stack

\anchor AXIOMSize0 \axiom size(): size(stack()) -> 0
\ref AXIOMTSize0 "Test"

\anchor AXIOMSize1 \axiom size(): For all S in Stack, size(push(S, X)) -> 1 + size(S)
\ref AXIOMTSize1 "Test"
**/
unsigned int size(const Stack& s)
{
    if (Stack {} == s) {
        return 0;
    } else {
        return 1 + size(rest(s));
    }
}

/** 
- OBSERVER
- CONTRACT: equal() : Stack, Stack -> Boolean
- PURPOSE:  return True if and only if two Stacks have the same content in the same order

\anchor AXIOMEqual0 \axiom equal(): For all S in Stack, equal(push(S, X), S) -> False
\ref AXIOMTEqual0 "Test"

\anchor AXIOMEqual1 \axiom equal(): For all S, S1 in Stack and X, X1, equal(push(S, X), push(S1, X1)) -> True if equal(S, S1) and X is equal X1 else False
\ref AXIOMTEqual1 "Test"

\anchor AXIOMEqual2 \axiom equal(): For all S in Stack , equal(S, S) -> True
\ref AXIOMTEqual2 "Test"

\anchor AXIOMEqual3 \axiom equal(): For all S and S1 in Stack , equal(S, S1) -> equal(S1, S)
\ref AXIOMTEqual3 "Test"
**/
bool equal(const Stack& lhs, const Stack& rhs)
{
    if (Stack {} == lhs && Stack {} == rhs) {
        return true;
    } // both empty are equal
    else if (Stack {} == lhs) {
        return false;
    } // one empty but not other are not equal
    else if (Stack {} == rhs) {
        return false;
    } // one empty but not other are not equal
    else {
        // equal only if both have same top and the rest of both are equal
        return ((top(lhs) == top(rhs)) && equal(rest(lhs), rest(rhs)));
    }
}

/** @} **/

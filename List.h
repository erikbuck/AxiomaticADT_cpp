//
//  List.h
//  CppAxiomsExample
//
//  Created by Erik M. Buck on 3/31/22.
//

#ifndef List_h
#define List_h

#include <vector>

/// This class exists to replicate the behavior of the Scheme List object. Scheme is a ["functional" programming language](https://en.wikipedia.org/wiki/Functional_programming) well suited for use with Algebraic/Axiomatic Abstract Data Type (ADT) definitions.
class List {
public:
    typedef std::vector<int>::const_iterator it_t;

private:
    /// Storage for the elements in the List
    std::vector<int> m_contents;

    /// Construct a List containing the elements enumerated by the begin and end iterators
    List(it_t begin, it_t end);

    /// Construct a List that is a copy of the List, other, with element appended.
    List(const List& other, int element);

    /// \return the "first" element in the List without mutating the List. ["car" is an esoteric acronym, ("contents of the address part of register number") for an IBM 704 computer from the late 1950s](https://en.wikipedia.org/wiki/CAR_and_CDR)
    friend int car(const List&);

    /// \return a List containing all elements except the "first" element in the List, l, without mutating l.  ["cdr" is an esoteric acronym, ("contents of the decrement part of register number") for an IBM 704 computer from the late 1950s](https://en.wikipedia.org/wiki/CAR_and_CDR)
    friend List cdr(const List& l);

    /// \return a List constructed as a copy of the List, l, with element appended. ["cons" is an esoteric name for an operation to creates a "cons cell" for an IBM 704 computer from the late 1950s](https://en.wikipedia.org/wiki/CAR_and_CDR). A "cons cell" is the data structure that contains the address and decrement parts referenced by "car" and "cdr".
    friend List cons(const List& l, int element);

    /// \return true if and only iff lhs and rhs contain the same number of elements and all elements in lhs are equal to the corresponding elements in rhs.
    friend bool operator==(const List& lhs, const List& rhs);

public:
    /// Construct an empty List
    List()
        : m_contents(std::vector<int>())
    {
    }

    /// Construct a copy of other
    List(const List& other)
        : m_contents(
            std::vector<int>(other.m_contents.begin(), other.m_contents.end()))
    {
    }
};

extern int car(const List& l);
extern List cdr(const List& l);
extern List cons(const List& l, int element);
bool operator==(const List& lhs, const List& rhs);

/// This is a synonym for car()
extern int first(const List& l);

/// This is a synonym for cdr()
extern List rest(const List& l);

/// This is a synonym for cons()
extern List append(const List& l, int element);

#endif /* List_h */

//
//  List.cpp
//  CppAxiomsExample
//
//  Created by Erik M. Buck on 3/31/22.
//

#include "List.h"

int car(const List& l) { return l.m_contents.back(); }

List cdr(const List& l)
{
    return List(l.m_contents.begin(), l.m_contents.end() - 1);
}

List cons(int element, const List& l) { return List(element, l); }

int first(const List& l) { return car(l); }
List rest(const List& l) { return cdr(l); }
List append(int element, const List& l) { return cons(element, l); }

bool operator==(const List& lhs, const List& rhs)
{
    return lhs.m_contents == rhs.m_contents;
}

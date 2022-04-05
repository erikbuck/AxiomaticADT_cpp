//
//  List.cpp
//  CppAxiomsExample
//
//  Created by Erik M. Buck on 3/31/22.
//

#include "List.h"

List::List(it_t begin, it_t end)
    : m_contents(std::vector<int>(begin, end))
{
}

List::List(const List& other, int element)
    : m_contents(
        std::vector<int>(other.m_contents.begin(), other.m_contents.end()))
{
    m_contents.push_back(element);
}

int car(const List& l) { return l.m_contents.back(); }

List cdr(const List& l)
{
    return List(l.m_contents.begin(), l.m_contents.end() - 1);
}

List cons(const List& l, int element) { return List(l, element); }

int first(const List& l) { return car(l); }
List rest(const List& l) { return cdr(l); }
List append(const List& l, int element) { return cons(l, element); }

bool operator==(const List& lhs, const List& rhs)
{
    return lhs.m_contents == rhs.m_contents;
}

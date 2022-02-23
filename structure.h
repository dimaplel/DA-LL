#ifndef ASD2_1_STRUCTURE_H
#define ASD2_1_STRUCTURE_H
#endif //ASD2_1_STRUCTURE_H

#include <iostream>
using namespace std;

struct President
{
    char name;
    float term;
    int palace_area;

    President(char i_name = '.', float i_term = 0, int i_palaceArea = 0)
    {
        name = i_name;
        term = i_term;
        palace_area = i_palaceArea;
    }

    ~President()
    = default;

    void print() const
    {
        cout << "Name: " << name << "; In service for: " << term << " years; Palace area: " << palace_area <<"\n";
    }
};
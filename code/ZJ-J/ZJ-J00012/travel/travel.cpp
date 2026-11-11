#include <bits/stdc++.h>
using namespace std;

int c1, row1, col1, c2, row2, col2, side1, side2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    char _;
    scanf("%d %d%c", &c1, &row1, &_);
    if (_ == 'A'){
        col1 = 1;
        side1 = 1;
    } else if (_ == 'B'){
        col1 = 2;
        side1 = 1;
    } else if (_ == 'C'){
        col1 = 3;
        side1 = 1;
    } else if (_ == 'D'){
        col1 = 4;
        side1 = 2;
    } else if (_ == 'F'){
        col1 = 5;
        side1 = 2;
    }
    scanf("%d %d%c", &c2, &row2, &_);
    if (_ == 'A'){
        col2 = 1;
        side2 = 1;
    } else if (_ == 'B'){
        col2 = 2;
        side2 = 1;
    } else if (_ == 'C'){
        col2 = 3;
        side2 = 1;
    } else if (_ == 'D'){
        col2 = 4;
        side2 = 2;
    } else if (_ == 'F'){
        col2 = 5;
        side2 = 2;
    }
    cout << (c1 == c2) << (c1 == c2 && row1 == row2);
    cout << (c1 == c2 && row1 == row2 && side1 == side2);
    cout << (c1 == c2 && row1 == row2 && side1 == side2 && abs(col1-col2) == 1);
}
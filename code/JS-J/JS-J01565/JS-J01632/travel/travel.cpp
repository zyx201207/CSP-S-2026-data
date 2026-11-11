#include <bits/stdc++.h>
using namespace std;

string c1,c2,c3,c4;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> c2 >> c3 >> c4;

    bool op1,op2,op3,op4;

    op1 = (c1 == c3);

    //cout << c2.substr(0,2) << endl;

    op2 = (c2.substr(0,2) == c4.substr(0,2));

    char a,b;
    a = c2[2];
    b = c4[2];

    if (a == 'F')a = 'E';
    if (b == 'F')b = 'E';

    if ((a <= 'C' && b <= 'C') || (a >= 'D' && b >= 'D'))op3 = true;
    else op3 = false;

    op4 = (abs(a - b) == 1);

    cout << op1 << (op1 & op2) << (op1 & op2 & op3) << (op1 && op2 && op3 && op4) << endl;

    return 0;
}

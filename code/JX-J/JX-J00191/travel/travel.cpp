#include <bits/stdc++.h>
using namespace std;
char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
int a1, a2, a3;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >>c2>> c3>> c4 >> c5 >> c6 >> c7 >> c8 >> c9 >> c10;
    if(c1==c6&&c2==c7)
    {
        cout << 1;
        a1++;
    }
    else{
        cout << 0;
    }
    if(a1==1)
    {
        if(c3==c8&&c4==c9)
        {
            cout << 1;
            a2++;
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
    if(a2==1)
    {
        if(c5=='A'&&c10=='B'||c5=='B'&&c10=='A'||c5=='A'&&c10=='C'||c5=='C'&&c10=='A'||c5=='C'&&c10=='B'||c5=='B'&&c10=='C'||c5=='D'&&c10=='F'||c5=='F'&&c10=='D')
        {
            cout << 1;
            a3++;
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
    if(a3 == 1)
    {
        if(c5=='A'&&c10=='B'||c5=='B'&&c10=='A'||c5=='C'&&c10=='B'||c5=='B'&&c10=='C'||c5=='D'&&c10=='F'||c5=='F'&&c10=='D')
            cout << 1;
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
    return 0;
}

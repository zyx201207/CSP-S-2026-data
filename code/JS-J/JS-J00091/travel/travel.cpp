#include<bits/stdc++.h>
using namespace std;
/* define & const */

/* struct */

/* Variables */
int a1, b1;
string a2, b2;
/* Function */
int where(char a)
{
    if (a == 'A' || a == 'B' || a == 'C')
        return 1;
    else
        return 0;
}
bool judge(char a, char b)
{
    int x = abs(a - b);
    bool flag = x == 1;
    if ((a == 'D' && b == 'F') || (a =='F' && b =='D'))
        flag = 1;
    return flag;
}
/* main */

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> a1 >> a2 >> b1 >> b2;
    if (a1 == b1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (a1 == b1 && a2[0] == b2[0] && a2[1] == b2[1])
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (a1 == b1 && a2[0] == b2[0] && a2[1] == b2[1] && where(a2[2]) == where(b2[2]))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    if (a1 == b1 && a2[0] == b2[0] && a2[1] == b2[1] && where(a2[2]) == where(b2[2]) && judge(a2[2], b2[2]))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    cout << "\n";
    return 0;
}
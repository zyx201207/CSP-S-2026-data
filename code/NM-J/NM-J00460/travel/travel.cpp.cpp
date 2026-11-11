#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t(string a,string b)
{
    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int p(string a,string b)
{
    if ((a[0] == b[0] && a[1] == b[1]) && t(c1,c2) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int side(string a,string b)
{
    if (((a[2] - 'A' <= 2 && b[2] - 'A' <= 2) || ((a[2] == 'D' && a[2] == 'E') && (b[2] == 'D' && b[2] == 'E'))) && (t(c1,c2) == 1 && p(s1,s2) == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int same(string a,string b)
{
    if ((abs(a[2] - b[2]) == 1) && (t(c1,c2) == 1 && (p(s1,s2) == 1 && side(s1,s2) == 1)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    cout << t(c1,c2) << p(s1,s2) << side(s1,s2) << same(s1,s2);
    return 0;
}

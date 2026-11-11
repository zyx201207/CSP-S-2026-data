#include<bits/stdc++.h>
using namespace std;

int side(char c)
{

    if(c == 'A'||c == 'B'||c == 'C')return 1;
    return 0;
}
bool near(char a,char b)
{
    if(a>b)swap(a,b);
    if(a == 'A')return b == 'B';
    if(a == 'B')return b == 'C';
    if(a == 'D')return b == 'F';
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
    {
        cout << "0000";
        return 0;
    }
    if(s1[0] != s2[0]||s1[1] != s2[1])
    {
        cout << "1000";
        return 0;
    }
    if(side(s2[2]) != side(s1[2]))
    {
        cout << "1100";
        return 0;
    }
    if(!near(s1[2],s2[2]))
    {
        cout << "1110";
        return 0;
    }
    cout << "1111";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int n=s1.size,m=s2.size;
    for(int i=1;i<=4;i++)
    {
        if(c1 == c2)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        if(n[0] == m[0] && n[1] == m[1])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        if(n[2]=="A" || n[2]=="B" || n[2]=="C" && m[2]=="A" || m[2]=="B" || m[2]=="C")
        {
            cout << 1;
        }
        else if(n[2]=="D" || n[2]=="F" && m[2]=="D" || m[2]=="F")
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        if(n[2]=="A" && m[2]=="B")
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        if(n[2]=="B" && m[2]=="C")
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        if(n[2]=="C" && m[2]=="D")
        {
            cout << 0;
        }
        if(n[2]=="D" && m[2]=="F")
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    return 0;
}

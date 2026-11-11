#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2;
    long long s1,s2;
    char a1,a2;
    cin >> c1 >> s1 >> a1 >> c2 >> s2 >> a2;
    if(c1==c2)
    {
        cout << 1;
    }
    else
    {
        cout << "0000";
        return 0;
    }
    if(s1==s2)
    {
        cout << 1;
        if(a1=='A'&&a2=='B')
        {
            cout << "11";
        }
        if(a1=='A'&&a2=='C')
        {
            cout << "10";
        }
        if(a1=='B'&&a2=='C')
        {
            cout << "11";
        }
        if(a1=='D'&&a2=='F')
        {
            cout << "11";
        }
        if(a2=='A'&&a1=='B')
        {
            cout << "11";
        }
        if(a2=='A'&&a1=='C')
        {
            cout << "10";
        }
        if(a2=='B'&&a1=='C')
        {
            cout << "11";
        }
        if(a2=='D'&&a1=='F')
        {
            cout << "11";
        }
    }
    else{
        cout << "000";
    }
    return 0;
}

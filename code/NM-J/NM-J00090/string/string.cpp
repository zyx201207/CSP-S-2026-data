#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,x,b=0;
    string s="";
    string a;
    string c="";
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >>x;
        cin>>a;
        for(int i=1;i<=x;i++)
        {
     	    s=s+a;
        }
    }
    for(int i=s.length();i>=1;i--)
    {
     	c=c+s[i];
    }
    for(int i=1;i<=s.length();i++)
    {
        if(s[i]!=c[i])
        {
            b++;
        }
    }
    cout << b;
    return 0;
}


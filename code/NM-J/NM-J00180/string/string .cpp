#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        string str="";
        for(int i=0;i<x;i++)
        {
            str[i]=y;
        }
        s+=str;
    }
    cout<<s;
}

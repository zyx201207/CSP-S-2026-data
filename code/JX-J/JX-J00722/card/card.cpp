#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500067],f[10089];
int vis[300043],finial[300043];
stack<long long> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int g=1;g<=m;g++)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[a[i]]==1 )
            {
                while(a[i]==s.top()) s.pop();
                vis[a[i]]=0;

            }
            else
            {
                vis[a[i]]=1;
                s.push(a[i]);
            }
        }
        long long cnt=1;
        for(int i=1;;i++)
        {
            cnt=i;
            if(s.empty()) break;
            else
            {
                cout<<s.top()<<' ';
                f[cnt]=s.top();
                finial[s.top()]++;
                s.pop();

            }
        }
        for(int i=cnt;i>=1;i--)
        {
            s.push(f[i]);
        }
    }
    for(int i=1;i<=300000;i++)
    {
        if(finial[i]!=0) cout<<finial[i]<<' ';
    }
    return 0;
}

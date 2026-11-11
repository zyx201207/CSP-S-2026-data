#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ct[300003],c[300003];
stack<int>s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int c[300003];
        memset(c,0,sizeof c);
        for(int j=i;j<=n;j++)
        {
            if(!c[a[j]])
            {
                s.push(a[j]),c[a[j]]++;
            }
            else
            {
                while(s.top()!=a[j])
                {
                    c[s.top()]--,s.pop();
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            ct[j]+=c[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ct[i]<<" ";
    }
    return 0;
}

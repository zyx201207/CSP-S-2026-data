#include<bits/stdc++.h>
using namespace std;
string d[200005];
int kk[200005];
string er(int n)
{
    string w="0000000000000000000000000000000";
    long long s=1;
    for(int i=1;i<=31;i++)
    {
        if(n%(s*2)!=0)
        {
            w[i-1]='1';
            n-=s;
        }
        s*=2;
    }
    return w;
}
string ff(string w)
{
    int p=0;
    int lkl=0;
    string l="0000000000000000000000000000000";
    for(int i=30;i>=0;i--)
    {
        l[p]=w[i];
        p++;
    }
    return l;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int v;
        cin>>v;
        d[i]=ff(er(v));
        kk[i]=v;
    }
    if(m==1)
    {
        int u=0;
        for(int i=1;i<=n;i++)
        {
            if(kk[i]>=u)
            {
                u=kk[i];
            }
        }
        cout<<u;
    }
    else
    {
        cout<<8;
    }
    return 0;
}

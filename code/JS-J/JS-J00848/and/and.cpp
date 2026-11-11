#include<bits/stdc++.h>
using namespace std;
int q[31];
int b[200005],o[200005];
int a[200005][31];
int l[200005];
int p[31][200005];
long long t[31];
long long c=0;
int dfs(int n,int m)
{
    if(n==m)
        return 0;
    for(int i=0;i<=30;i++)
        q[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=l[b[i]];j++)
            if(a[b[i]][j])
            q[j]++;
    int z=-1;
    for(int i=30;i>=0;i--)
    if(q[i]>=m)
    {
        z=i;
        break;
    }
    if(z==-1)
        return 0;
    else
    {
        c+=t[z];
        for(int i=1;i<=n;i++)
            o[i]=b[i];
        int op=1;
        for(int i=1;i<=n;i++)
            if(a[o[i]][z])
            b[op++]=o[i];
        for(int i=1;i<=q[z];i++)
            a[b[i]][z]=0;
        dfs(q[z],m);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    t[0]=1;
    for(int i=1;i<=30;i++)
        t[i]=t[i-1]*2;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        long long d;
        cin>>d;
        while(d)
        {
            a[i][l[i]++]=(d%2);
            if(d%2)
            {
                p[l[i]-1][0]++;
                p[l[i]-1][p[l[i]-1][0]]=i;
            }
            d/=2;
        }
    }
    int z=-1;
    for(int i=30;i>=0;i--)
    if(p[i][0]>=m)
    {
        z=i;
        break;
    }
    if(z==-1)
    cout<<0;
    else
    {
        c+=t[z];
        for(int i=1;i<=p[z][0];i++)
            a[p[z][i]][z]=0;
        for(int i=1;i<=p[z][0];i++)
            b[i]=p[z][i];
        dfs(p[z][0],m);
    }
    cout<<c;
    return 0;
}

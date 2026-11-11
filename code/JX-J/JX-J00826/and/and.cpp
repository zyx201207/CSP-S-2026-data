#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005][100],r[100],id[200005],d[200005],l[100],maxn=0,e[200005];
void dfs(int c)
{
    if(c==m)
    {
        for(int i=1; i<=31; i++)
        {
            l[i]=b[d[1]][i];
        }
        for(int i=2; i<=m; i++)
        {
            for(int j=1; j<=31; j++)
            {
                if(l[j]==1 && b[d[i]][j]==1) l[j]=1;
                else l[j]=0;
            }
        }
        long long s=0;
        for(int i=1; i<=31; i++)
        {
            if(l[i]==1) s=s+r[i];
        }
        if(s>maxn) maxn=s;
    }
    for(int i=1; i<=n; i++)
    {
        if(id[i]==0)
        {
            id[i]=1;
            d[c+1]=i;
            dfs(c+1);
            id[i]=0;
            d[c+1]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    r[1]=1;
    memset(b,0,sizeof(b));
    memset(id,0,sizeof(id));
    for(int i=2; i<=31; i++)
    {
        r[i]=r[i-1]*2;
    }
    long long maxm=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        e[i]=a[i];
        if(a[i]>maxm) maxm=a[i];
        for(int j=31; j>=1; j--)
        {
            if(a[i]>=r[j])
            {
                b[i][j]=1;
                a[i]=a[i]-r[j];
            }
        }
    }
    int flag=1;
    for(int z=1; z<=n; z++)
    {
        for(int i=1; i<=31; i++)
        {
            if(e[z]==r[i]-1) break;
            else if(i==31) flag=0;
        }
        if(flag==0) break;
    }
    sort(e+1,e+1+n);
    if(flag==1) cout<<e[n-m+1]<<endl;
    else if(m==1) cout<<maxm<<endl;
    else if(m==n)
    {
        for(int i=1; i<=31; i++)
        {
            l[i]=b[1][i];
        }
        for(int i=2; i<=m; i++)
        {
            for(int j=1; j<=31; j++)
            {
                if(l[j]==1 && b[i][j]==1) l[j]=1;
                else l[j]=0;
            }
        }
        long long s=0;
        for(int i=1; i<=31; i++)
        {
            if(l[i]==1) s=s+r[i];
        }
        cout<<s<<endl;
    }
    else if(m==n-1)
    {
        long long maxc=0;
        for(int z=1; z<=n; z++)
        {
            if(z==1)
            {
                for(int i=1; i<=31; i++)
                {
                    l[i]=b[2][i];
                }
            }
            else
            {
                for(int i=1; i<=31; i++)
                {
                    l[i]=b[1][i];
                }
            }
            for(int i=2; i<=m; i++)
            {
                if(i!=z)
                {
                    for(int j=1; j<=31; j++)
                    {
                        if(l[j]==1 && b[i][j]==1) l[j]=1;
                        else l[j]=0;
                    }
                }
            }
            long long s=0;
            for(int i=1; i<=31; i++)
            {
                if(l[i]==1) s=s+r[i];
            }
            if(maxc<s) maxc=s;
        }
        cout<<maxc<<endl;
    }
    else
    {
        dfs(0);
        cout<<maxn<<endl;
    }
    return 0;
}

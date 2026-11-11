#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
const int MAXM=3e5+10;
int n,m;
int a[MAXN];
int f[MAXM];
int cnt;
int p[MAXN];
int lst[MAXM];
bool used[MAXN];
signed main()
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
        cnt=0;
        for(int j=1;j<=n;j++)
        {
            used[j]=false;
        }
        for(int j=i;j<=n;j++)
        {
            bool flag=false;
            for(int x=1;x<=cnt;x++)
            {
                if(p[x]==a[j]&&!used[x])
                {
                    flag=true;
                    used[x]=true;
                }
                if(flag)
                {
                    used[x]=true;
                }
            }
            p[++cnt]=a[j];
        }
        for(int j=1;j<=cnt;j++)
        {
            if(!used[j])
            {
                f[p[j]]++;
            }
            // cout<<used[j]<<' ';
        }
        // cout<<'\n';
    }
    for(int i=1;i<=m;i++)
    {
        cout<<f[i]<<' ';
    }
    return 0;
}
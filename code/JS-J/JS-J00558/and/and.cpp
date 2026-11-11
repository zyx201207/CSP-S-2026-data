#include<bits/stdc++.h>
using namespace std;
const int maxn=200001;
int n,m,a[maxn],ans;
bool f[maxn][31],vis[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int num=a[i];
        for(int j=0;j<30;j++)
        {
            f[i][j]=num&1;
            num>>=1;
        }
    }
    for(int i=1;i<=n;i++)  vis[i]=1;
    for(int j=29;j>=0;j--)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(vis[i]&&f[i][j])
                cnt++;
        if(cnt<m) continue;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]&&f[i][j]) continue;
            vis[i]=0;
        }
        ans+=(1<<j);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
4 2
3 15 12 12
12

5 3
31 3 1 15 7
*/
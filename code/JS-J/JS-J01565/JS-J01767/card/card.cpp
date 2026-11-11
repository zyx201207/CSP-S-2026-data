#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5*100010;
const int M = 3*100010;
int a[N];
int nxt[M];
int lst[M];
int ans[M];
bool vis[M];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i = 1;i<=n;i++)
    {
        cin>>a[i];
        if(lst[a[i]])
            nxt[lst[a[i]]]=i;
        lst[a[i]]=i;
    }

    for (int i = 1;i<=n;i++)
    {
        for (int j = i;j<=n;j++)
        {
            if(nxt[j])
            {
                j=nxt[j]-1;
                continue;
            }
            if(!vis[a[j]])
            {
                ans[a[j]]++;
                vis[a[j]]=1;
            }
        }
        for (int j = 1;j<=m;j++)
            vis[j]=0;
    }
    for (int i = 1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}

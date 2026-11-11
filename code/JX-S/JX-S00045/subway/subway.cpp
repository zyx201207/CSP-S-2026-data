#include<bits/stdc++.h>
using namespace std;
int w[500010];
vector<int> a[500010];
unordered_map<int,long long> t[500010];
long long l[510][510];
vector<int> e[500010];
int k[500010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int i,j;
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++) cin>>w[i];
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) l[i][j]=1e18;
    for(i=1;i<=n;i++) l[i][i]=0;
    for(i=1;i<=n;i++)
    {
        cin>>k[i];
        a[i].resize(k[i]+2);
        for(j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][a[i][j]],e[a[i][j]].push_back(i);
    }
    // for(i=1;i<=m;i++)
    // {
    //     for(auto x:e[i]) cout<<i<<" "<<x<<" "<<t[x][i]<<"\n";
    // }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k[i];j++)
        {
            // cout<<i<<" "<<j<<"\n";
            for(auto nxt:e[a[i][j]])
            {
                // cout<<i<<" "<<a[i][j]<<" "<<nxt<<"\n";
                l[i][nxt]=l[nxt][i]=min(l[i][nxt],1ll*(t[i][a[i][j]]+t[nxt][a[i][j]])); 
            }
        }
    }
    for(int o=1;o<=n;o++) for(i=1;i<=n;i++) for(j=1;j<=n;j++) l[i][j]=min(l[i][j],l[i][o]+l[o][j]);
    // for(i=1;i<=n;i++,cout<<"\n") for(j=1;j<=n;j++) cout<<l[i][j]<<" ";
    while(q--)
    {
        int S,T;
        cin>>S>>T;
        // cout<<S<<" "<<T<<"\n";
        long long da=1e18;
        for(auto x:e[S]) for(auto y:e[T])
        {
            da=min(da,t[x][S]+t[y][T]+l[x][y]);
        }
        cout<<da+w[S]+w[T]<<"\n";
    }
    return 0;
}

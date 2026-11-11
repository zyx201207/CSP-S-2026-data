#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[500005];
vector<pair<int,int>> v[500005];
ll f[505][505];

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    memset(f,0x3f,sizeof(f));

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            cin>>x>>t;
            v[x].emplace_back(i,t);
        }
    }
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)v[i].size();j++){
            int x=v[i][j].first,tx=v[i][j].second;
            for(int k=j+1;k<(int)v[i].size();k++){
                int y=v[i][k].first,ty=v[i][k].second;
                f[x][y]=min(f[x][y],(ll)tx+ty);
                f[y][x]=min(f[y][x],(ll)tx+ty);
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(i==j||j==k||i==k)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<(int)v[x].size();i++){
            int idx=v[x][i].first,tx=v[x][i].second;
            for(int j=0;j<(int)v[y].size();j++){
                int idy=v[y][j].first,ty=v[y][j].second;
                ans=min(ans,a[x]+tx+f[idx][idy]+ty+a[y]);
            }
        }
        cout<<ans<<'\n';
    }

}
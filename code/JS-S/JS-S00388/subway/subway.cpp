#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll w[N],n,m,d,q,k,t[505][505],u,v,ans,x,y;
vector<int> rd[N];
vector<int> xi[N];
int c;
void solve(){
    ll mt=w[x]+w[y];
    for(int i=0;i<rd[x].size();i++){
        int xian=rd[x][i];
        for(int j=0;j<xi[xian].size();j++){
            int zhan=xi[xian][j];
            if(zhan==y) ans=min(ans,t[xian][x]+t[xian][y]+mt);
            for(int k=0;k<rd[y].size();k++){
                int xianer=rd[y][k];
                if(xianer==xian) continue;
                for(int f=0;f<xi[xianer].size();f++){
                    int zhaner=xi[xianer][f];
                    if(zhan==zhaner){
                        ans=min(ans,mt+t[xian][x]+t[xian][zhan]+t[xianer][zhaner]+t[xianer][y]);
                    }

                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>u>>v;
            rd[u].push_back(i);
            xi[i].push_back(u);
            t[i][u]=v;
        }
    }
    //cout<<rd[1][0]<<endl;
    while(q--){
        ans=99999999999999999;
        cin>>x>>y;
        solve();
        cout<<ans<<endl;
    }
    return 0;
}

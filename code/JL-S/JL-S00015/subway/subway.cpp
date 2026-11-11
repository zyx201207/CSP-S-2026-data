#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[550000];
long long e[550][550],f[550][550];
int k[550],a,t;
vector<pair<int,int>>v[550000];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) e[i][j]=0x3f3f3f3f3f3f3f3f;
            else e[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=0;k<v[i].size();k++){
                if(j==k) continue;
                e[v[i][j].first][v[i][k].first]=min(e[v[i][j].first][v[i][k].first],1ll*v[i][j].second+v[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=e[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        cin>>a>>t;
        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<v[a].size();i++){
            for(int j=0;j<v[t].size();j++){
                ans=min(ans,1ll*v[a][i].second+v[t][j].second+f[v[a][i].first][v[t][j].first]+w[a]+w[t]);
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}

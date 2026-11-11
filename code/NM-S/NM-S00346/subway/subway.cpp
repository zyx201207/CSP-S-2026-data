#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,c,d,q,w[500050],k[550],cnt[505][500005];
vector<int> a[550],t[550],pass[500050];
ll dis[550][550];
struct st{
    int id;
    ll v;
};
vector<int>e[550];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dis[i][j] = 1e18;
        }
    }
    for(int i = 1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j = 1;j<=k[i];j++){
            int x,y;
            scanf("%d%d",&x,&y);
            cnt[i][x] = j-1;
            a[i].push_back(x);
            t[i].push_back(y);
            pass[x].push_back(i);
        }
    }
    for(int i = 1;i<=m;i++){
        if(pass[i].size()<=1)continue;
        for(int j = 0;j<pass[i].size();j++){
            e[pass[i][j]].push_back(i);
        }
    }
    for(int i = 1;i<=n;i++){
        queue<st> qq;
        qq.push({i,0});
        dis[i][i] = 0;
        while(!qq.empty()){
            st top = qq.front();
            qq.pop();
            for(int j = 0;j<e[top.id].size();j++){
                int xx = e[top.id][j];
                for(int k = 0;k<pass[xx].size();k++){
                    int yy = pass[xx][k];
                    if(yy == top.id)continue;
                    ll vv = 1ll*(top.v+t[top.id][cnt[top.id][xx]]+t[yy][cnt[yy][xx]]);
                    if(vv>=dis[i][yy])continue;
                    dis[i][yy]  = dis[yy][i] = vv;
                    qq.push({yy,vv});
                }
            }
        }
    }
    int x,y;
    while(q--){
        cin>>x>>y;
        ll ans = 1e18;
        for(int i = 0;i<pass[x].size();i++){
            for(int j = 0;j<pass[y].size();j++){
                int xx = pass[x][i],yy = pass[y][j];
                ans = min(ans,1ll*(dis[xx][yy]+t[xx][cnt[xx][x]]+t[yy][cnt[yy][y]]));
            }

        }
        cout<<1ll*(ans+w[x]+w[y])<<endl;
    }
	return 0;
}

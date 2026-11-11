#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int> >zzs;
vector<int>kzs;
vector<int>vis;
int dian;
int ans=9999999;
int gong=0;
queue<int>qq;
 int c,n,m,d,q;
void bfs(int x){
    if(x=dian){
        ans=min(ans,gong);
        return;
    }
    for(int i=1;i<=n;i++){
        if(zzs[x][i]!=0){
            vis[x]=1;

            gong+=kzs[x]+zzs[x][i];
            for(int j=1;j<=n;j++){
                if(!vis[j]&&zzs[j][i]!=0){
                    qq.push(j);
                    gong+=zzs[j][i];
                    vis[x]=0;
                }
            }
            while(qq.size()!=0){
                int e=qq.front();
                bfs(e);
            }
        }
    }
    gong+=kzs[dian];
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    zzs.assign(m+1,vector<int>(d+1));
    kzs.assign(m+1,0);
    kzs.assign(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>kzs[i];
    }
    int xian=1;
    while(n--){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            zzs[x][xian]=y;
        }
        xian++;
    }

    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        dian=y;
        gong=0;
        bfs(x);
        cout<<ans<<'\n';
    }
    return 0;
}

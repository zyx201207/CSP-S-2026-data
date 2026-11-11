#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,kk[505],t[500005],ans,flagg=1;
bool vis[505][500005];
struct lne{
    int pp,tt;
}line[505][250005];
queue<pair<pair<int,int>,int> > qq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>t[i];
    }
    for(int i=1;i<=n;i++){
        cin>>kk[i];
        if(kk[i]>2)flagg=0;
        for(int j=1;j<=kk[i];j++){
            cin>>line[i][j].pp>>line[i][j].tt;

        }
    }
    if(flagg)
        for(int i=1;i<=q;i++){
            ans=INT_MAX;
            int a,b;
            bool flag=0;
            cin>>a>>b;
            for(int j=1;j<=n;j++){
                if(kk[i]!=1){
                    if(line[j][1].pp==a){
                        memset(vis,0,sizeof(vis));
                        qq.push({{j,1},0});
                        vis[j][1]=1;
                        while(!qq.empty()){
                            int ni=qq.front().first.first;
                            int nj=qq.front().first.second;
                            int nstep=qq.front().second;
                            if(line[ni][nj].pp==b)ans=min(ans,nstep);
                            qq.pop();
                            for(int o=1;o<=n;o++){
                                if(o!=j){
                                if(line[o][1].pp==line[ni][nj].pp && !vis[o][1]){
                                    qq.push({{o,1},nstep+line[o][1].tt+line[ni][nj].tt});
                                    vis[o][1]=1;
                                }
                                if(line[o][2].pp==line[ni][nj].pp && !vis[o][2]){
                                    qq.push({{o,2},nstep+line[o][2].tt+line[ni][nj].tt});
                                    vis[o][2]=1;
                                }
                                }
                            }
                            if(!vis[ni][nj==1?2:1]){
                                qq.push({{ni,(nj==1?2:1)},nstep});
                                vis[ni][nj==1?2:1]=1;
                            }
                        }
                    }
                    if(line[j][2].pp==a){
                        memset(vis,0,sizeof(vis));
                        qq.push({{j,2},0});
                        vis[j][2]=1;
                        while(!qq.empty()){
                            int ni=qq.front().first.first;
                            int nj=qq.front().first.second;
                            int nstep=qq.front().second;
                            if(line[ni][nj].pp==b)ans=min(ans,nstep);
                            qq.pop();
                            for(int o=1;o<=n;o++){
                                if(o!=j){
                                if(line[o][1].pp==line[ni][nj].pp && !vis[o][1]){
                                    qq.push({{o,1},nstep+line[o][1].tt+line[ni][nj].tt});
                                    
                                    vis[o][1]=1;
                                }
                                if(line[o][2].pp==line[ni][nj].pp && !vis[o][2]){
                                    qq.push({{o,2},nstep+line[o][2].tt+line[ni][nj].tt});
                                    
                                    vis[o][2]=1;
                                }
                                }
                            }
                            if(!vis[ni][nj==1?2:1]){
                                qq.push({{ni,(nj==1?2:1)},nstep});
                                
                                vis[ni][nj==1?2:1]=1;
                            }
                        }
                    }
                }
            }
            cout<<ans+t[a]+t[b]<<endl;
        }
    if(n==2){
        for(int o=1;o<=q;o++){
            int a,b;
            cin>>a>>b;
            cout<<t[1]+t[2];
        }
        return 0;
    }
    return 0;
}
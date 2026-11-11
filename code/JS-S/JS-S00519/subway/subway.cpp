#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
ll dis[510][510];
vector<int> g[500010],t[500010];
ll w[500010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    int c,n,m,d,q,x,y,k,a,tt;
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a;
            g[a].push_back(i);
            cin>>tt;
            t[a].push_back(tt);
        }
    }
    
    for(int k=1;k<=m;k++){
        for(int i=0;i<g[k].size();i++){
            for(int j=0;j<g[k].size();j++){
                if(i==j)dis[g[k][i]][g[k][j]]=0;
                else{
                    dis[g[k][i]][g[k][j]]=dis[g[k][j]][g[k][i]]=min(dis[g[k][i]][g[k][j]],((ll)(t[k][i])+t[k][j]));
                }            
            }
        }
    }

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==inf)cout<<-1<<" ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------"<<endl;*/

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]!=inf&&dis[k][j]!=inf){
                    if(dis[i][k]+dis[k][j]<dis[i][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
    }

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==inf)cout<<-1<<" ";
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------"<<endl;*/

    ll ans=0,res=0;
    while(q--){
        cin>>x>>y;
        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                res=dis[g[x][i]][g[y][j]];
                res+=w[x];
                res+=w[y];
                res+=t[x][i];
                res+=t[y][j];
                //cout<<"res="<<res<<endl;
                ans=min(ans,res);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
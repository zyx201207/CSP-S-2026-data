#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
const int N=1e3+5;
int c,n,m,d,q;
int w[N];
vector<pii>g[N];
int dis[N][N],vis[N];
int t[2][500005];
void qrw(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}
void dij(int st){
    priority_queue<pii,vector<pii>,greater<pii> >q;
    memset(vis,0,sizeof vis);
    q.push({0,st});
    dis[st][st]=0;
    while(!q.empty()){
        auto [w,u]=q.top();
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto [w1,v]:g[u]){
        	//cout<<w1<<" ";
            if(dis[st][u]+w1<dis[st][v]){
                dis[st][v]=dis[st][u]+w1;
                q.push({dis[st][v],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    qrw();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c<=11&&c>=7){
        for(int i=1,k;i<=n;i++){
	        cin>>k;
	        int u,v,w1,w2;
	        cin>>u>>w1>>v>>w2;
	        w1+=w2;
	        g[u].pb({w1,v});
	        g[v].pb({w1,u});
	    }
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=m;j++){
	            dis[i][j]=LLONG_MAX/4;
	        }
	    }
	    for(int i=1;i<=m;i++){
	        dij(i);
	    }
	    int x,y;
	    while(q--){
	        cin>>x>>y;
	        cout<<dis[x][y]+w[x]+w[y]<<"\n";
	    }
    }else if(c==20||c==21){
        for(int i=1,k;i<=n;i++){
            cin>>k;
            for(int j=1,a1,t1;j<=k;j++){
                cin>>a1>>t1;
                t[i-1][a1]=t1;
            }
	    }
        int x,y;
        if(n==1){    
            while(q--){
                cin>>x>>y;
                cout<<t[0][x]+t[0][y]+w[x]+w[y]<<"\n";
            }
        }else{
            int minn=LLONG_MAX/4;
            for(int i=1;i<=m;i++){
                if(t[0][i]&&t[1][i]){
                    minn=min(minn,t[0][i]+t[1][i]);
                }
            }
            while(q--){
                int ans=LLONG_MAX/4;
                cin>>x>>y;
                if((t[0][x]&&t[0][y])||(t[1][x]&&t[1][y])){//same line
                    if(t[0][x]){
                        ans=t[0][x]+t[0][y];
                    }
                    if(t[1][x]){
                        ans=min(ans,t[1][x]+t[1][y]);
                    }
                }else{
                    if(t[0][x]){//x in 0 line
                        ans=t[0][x]+t[1][y]+minn;
                    }else{
                        ans=t[1][x]+t[0][y]+minn;
                    }
                }
                cout<<ans+w[x]+w[y]<<"\n";
            }
            
        }
    }
    return 0;
}//28pts

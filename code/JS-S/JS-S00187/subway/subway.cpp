#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int M=5e5+10,N=550;
int c,n,m,d,t,ans;
int disstt[1050][1050],a[M],dist[1050];
vector<pair<int,int> > G[M];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    if(c>=7&&c<=11){
        for(int i=1;i<=n;i++){
            int k,x,y,x_dist,y_dist;
            cin>>k>>x>>x_dist>>y>>y_dist;
            G[x].push_back({y,x_dist+y_dist});
            G[y].push_back({x,x_dist+y_dist});
        }
        for(int k=1;k<=m;k++){
            multiset<pair<int,int> > st;
            memset(dist,0x3f,sizeof(dist));
            dist[k]=0;
            st.insert({dist[k],k});
            while(!st.empty()){
                int u=(*st.begin()).se,distt=(*st.begin()).fi;
                st.erase(st.begin());
                if(dist[u]<distt)continue;
                for(auto v:G[u]){
                    if(dist[v.fi]>distt+v.se)
                        dist[v.fi]=distt+v.se,st.insert({dist[v.fi],v.fi});
                }
            }
            for(int i=1;i<=m;i++)
                disstt[k][i]=dist[i];
        }
        while(t--){
            int x,y;
            cin>>x>>y;
            cout<<disstt[x][y]+a[x]+a[y]<<"\n";
        }
    }
    return 0;
}

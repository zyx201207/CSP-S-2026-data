#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q1;
struct node{
    int v,sub;
};
struct node1{
    int v,sub,dis;
};
ll w[5*100009];
int k[5*100009];
ll t[500][5*100009];
int dis[500009],vis[500009];
map<pair<int,int>,int> mp;
vector<node> vt[5*100009];

queue<node1> q;
void spfa(int s){
    for(int i=1;i<=n;i++){
        if(mp.find({s,i})!=mp.end()){
            q.push({s,i,t[i][s]});
            dis[s]=0;
        }
    }
    vis[s]=1;
    while(!q.empty()){
        node1 cur=q.front();
        q.pop();

        for(int i=0;i<vt[cur.v].size();i++){
            node nextt=vt[cur.v][i];
            if(mp.find({nextt.v,cur.sub})!=mp.end()){
                if(dis[nextt.v]>cur.dis+t[cur.sub][nextt.v]){
                    dis[nextt.v]=cur.dis+t[cur.sub][nextt.v];
                    //cout<<"disch: "<<dis[nextt.v]<<"\n";
                    if(!vis[nextt.v]){
                        vis[nextt.v]=1;
                        q.push({nextt.v,cur.sub,cur.dis});
                    }
                }
            }else{
                if(dis[nextt.v]>cur.dis+t[cur.sub][cur.v]+t[nextt.sub][cur.v]+t[nextt.sub][nextt.v]){
                    dis[nextt.v]=cur.dis+t[cur.sub][cur.v]+t[nextt.sub][cur.v]+t[nextt.sub][nextt.v];
                    if(!vis[nextt.v]){
                        vis[nextt.v]=1;
                        q.push({nextt.v,cur.sub,dis[nextt.v]});
                    }
                }
            }
            //cout<<"cur: "<<cur.v<<"\n"<<"nextt: "<<nextt.v<<"\n";
            //for(int i=1;i<=m;i++){
            //        cout<<dis[i]<<" ";
            //    }
            //cout<<"\n";
            }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>n>>m>>d>>q1;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        int pre=0;
        for(int j=1;j<=k[i];j++){
            int a;
            cin>>a>>t[i][a];
            //cout<<"i,a,t: "<<i<<" "<<a<<" "<<t[i][a]<<"\n";
            mp[{a,i}]=1;
            vt[pre].push_back({a,i});
            pre=a;
        }
    }
    if(c>=1&&c<=6){//cout<<"#\n";
        while(q1--){
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            int ans=0;
            int sta,en;
            cin>>sta>>en;
            ans=ans+w[sta]+w[en];
            //cout<<ans<<"\n";
            spfa(sta);
            //cout<<"@\n";
            //for(int i=1;i<=m;i++){
            //    cout<<dis[i]<<" ";
            //}
            //cout<<"\n";
            ans+=dis[en];
            cout<<ans<<"\n";
        }
    }else if(c>=7&&c<=11){
        while(q1--){
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            int ans=0;
            int sta,en;
            cin>>sta>>en;
            ans=ans+w[sta]+w[en];
            //cout<<ans<<"\n";
            spfa(sta);
            //cout<<"@\n";
            //for(int i=1;i<=m;i++){
            //    cout<<dis[i]<<" ";
            //}
            //cout<<"\n";
            ans+=dis[en];
            cout<<ans<<"\n";
        }
    }else if(c>=12&&c<=19){
        while(q1--){
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            int ans=0;
            int sta,en;
            cin>>sta>>en;
            ans=ans+w[sta]+w[en];
            //cout<<ans<<"\n";
            spfa(sta);
            //cout<<"@\n";
            //for(int i=1;i<=m;i++){
            //    cout<<dis[i]<<" ";
            //}
            //cout<<"\n";
            ans+=dis[en];
            cout<<ans<<"\n";
        }
    }else{
        while(q1--){
            memset(dis,0x3f,sizeof(dis));
            memset(vis,0,sizeof(vis));
            int ans=0;
            int sta,en;
            cin>>sta>>en;
            ans=ans+w[sta]+w[en];
            //cout<<ans<<"\n";
            spfa(sta);
            //cout<<"@\n";
            //for(int i=1;i<=m;i++){
            //    cout<<dis[i]<<" ";
            //}
            //cout<<"\n";
            ans+=dis[en];
            cout<<ans<<"\n";
        }
    }
    return 0;
}

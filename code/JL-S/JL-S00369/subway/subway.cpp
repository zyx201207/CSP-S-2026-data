#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct aa{
int v,z;
};
int k[200002];
vector<aa> g[2000001];
int w[500001];
int zn;
int dis[200001];
bool vis[200001];
struct bb{
int dd,jz;

bool operator <(const bb &o)const {
return jz>o.jz;
}
};
void dj(int s,int t){int lpp=0;
    for(int i=1;i<=zn;i++) dis[i]=1e9;
    for(int i=1;i<=zn;i++) vis[i]=0;
priority_queue<bb> q;
q.push({s,0});
dis[s]=0;
while(!q.empty()){
        //cout<<"1";
    bb u=q.top();
    q.pop();
    //cout<<u.dd<<" ";
    if(vis[u.dd])
       continue;
    vis[u.dd]=1;
    if(u.dd==t)
        return;
    for(auto kkk:g[u.dd]){
        if(dis[kkk.v]>dis[u.dd]+kkk.z&&vis[kkk.v]==0){
         //       lpp++;
         //       cout<<kkk.v<<" "<<kkk.z<<" "<<dis[kkk.v]<<" "<<dis[u.dd]+kkk.z<<"\n";
                if(lpp==9){
                    return;
                }
            dis[kkk.v]=dis[u.dd]+kkk.z;
            q.push({kkk.v,dis[kkk.v]});
        }
    }
}
return;

}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>w[i];
}
zn=m;
for(int i=1;i<=n;i++){
    cin>>k[i];
    zn++;
    for(int j=1;j<=k[i];j++){
     int o,oo;
     cin>>o>>oo;
     g[zn].push_back({o,oo});
     g[o].push_back({zn,oo});
    }
}
//dj(1,3);
//for(int i=1;i<=zn;i++){
   // for(auto kkk:g[i]){
   //     cout<<kkk.v<<" "<<kkk.z<<"\n";
   // }
   // cout<<"\n";
//}
while(q--){
    int x,y;
    cin>>x>>y;
    dj(x,y);
    cout<<dis[y]+w[x]+w[y]<<"\n";
}
return 0;
}

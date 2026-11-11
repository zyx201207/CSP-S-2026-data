#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct path{
    long long u,v,w;
};
struct node{
    int time;
    vector<path> paths;
}a[501005];

long long dis[501005];
bool operator <(path a,path b){
    return a.w>b.w;
} 
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i].time;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long s1,s2;
            cin>>s1>>s2;
            path s;
            s.u=m+i;
            s.v=s1;
            s.w=s2;
            a[m+i].paths.push_back(s);
            s.u=s1;
            s.v=m+i;
            a[s1].paths.push_back(s);
        }
    }
    
    while(q--){
        int uu,vv;
        long long ans=0;
        cin>>uu>>vv;
        memset(dis,0x3f,sizeof(dis));
        
        priority_queue<path,vector<path>> pq;
        dis[0]=0;
        pq.push({0,uu,0});
        while(!pq.empty()){
            path f=pq.top();
            pq.pop();
            if((dis[f.u]+f.w)>dis[f.v]){
                continue;
            }
            //cout<<f.u<<":";
            dis[f.v]=dis[f.u]+f.w;
            if(f.v==vv)continue;
            for(int i=0;i<a[f.v].paths.size();i++){
                if(a[f.v].paths[i].v==f.v) continue;
                pq.push(a[f.v].paths[i]);
            }
        }
        cout<<dis[vv]+a[uu].time+a[vv].time<<'\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> g[1200006];
int dis[1200006][2];
void BFS(int x,int fa,int opt,int zhi){
    dis[x][opt]=zhi;
    for(int v:g[x]){
        if(v==fa){
            continue;
        }
        BFS(v,x,opt,zhi+1);
    }
}
int Max[1200006],Ans,col[1200006],Mid,dep[1200006];
void solve(int cur,int fa,int opt){
    int Chk=0;
    for(int v:g[cur]){
        if(v==fa || col[v]!=opt){
            continue;
        }
        dep[v]=dep[cur]+1;
        solve(v,cur,opt);
        Max[cur]=max(Max[cur],Max[v]);
    }
    Max[cur]=max(Max[cur],dep[cur]);
    if(Max[cur]-dep[cur]>=Mid){
        Chk=1;
    }
    if(fa==0){
        Chk=1;
    }
    Ans+=Chk;
}
int n,m;
void Clear(){
    for(int i=0;i<=n+1;i++){
        Max[i]=0;
        dep[i]=0;
    }
}
bool check(int mid){
    Mid=mid;
    for(int i=1;i<=n;i++){
        Clear();
        Ans=0;
        for(int j=1;j<=n;j++){
            col[j]=1;
        }
        solve(i,0,1);
        if(Ans<=m){
            return 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            Clear();
            Ans=0;
            BFS(i,0,0,0);
            BFS(j,0,1,0);
            for(int num=1;num<=n;num++){
                if(dis[num][0]<=dis[num][1]){
                    col[num]=1;
                }else{
                    col[num]=2;
                }
            }
            solve(i,0,1);
            Clear();
            solve(j,0,2);
            if(Ans<=m){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=2;i<=n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int l=0,r=n,ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
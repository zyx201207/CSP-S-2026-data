#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
int a[MN];
vector<int>g[MN];
int cnr,ans;
queue<int>q;
int bfs(int s,int t){
    int sum=0;
    int cnt=0;
    int sum=0x3f3f3f3f;
    queue<pair<int,int>>q;
    q.push({s,0});
    while(!q.empty()){
        auto u=q.;
        auto
        for(auto v:g[u]){
            if(v==t){
                if(cnt==0){
                    sum=w+1;
                    cnt++;
                }else{
                    if(w+1==sum){
                        cnt++;
                    }
                }
                continue;
            }
            q.push({v,w+1});
        }
    }
}
int main () {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;

    }
    int ans=0;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]<=d){
                g[i].push_back(j);
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int cnt=bfs(i,j);
            if(cnt==2){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
        return 0;
}

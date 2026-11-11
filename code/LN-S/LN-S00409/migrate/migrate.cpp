#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int c,t;
const int MAXN = 2e6+5;
long long x[MAXN];
int n;
long long d;
vector<vector<int>>g(MAXN);
int dis[MAXN];
int cnt[MAXN];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1;i<=n;i++) cin>>x[i];
        if(1){
            for(int i = 1;i<=n;i++){
                dis[i] = 0x3f3f3f3f;
                for(int j = i+1;j<=n;j++){
                    int dis1 = abs(x[i]-x[j]);
                    if(dis1<=d) g[i].push_back(j);
                }
            }
            queue<int> q;
            q.push(1);
            dis[1] = 0;
            cnt[1] = 1;
            int ans = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v:g[u]){
                    if(dis[v]>dis[u]+1){
                        dis[v] = dis[u]+1;
                        cnt[v] = 1;
                        q.push(v);
                    }
                    else if(dis[v]==dis[u]+1){
                        cnt[v]++;
                        q.push(v);
                    }
                }
            }
            for(int i = 1;i<=n;i++) ans+=cnt[i];
            cout<<ans<<"\n";
        }
    }
}

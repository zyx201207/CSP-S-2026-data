#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 0x3f3f3f3f3f3f3f3f;
int n,k;
int a[5005];

vector<int> fuck[5005];
void init(){
    int p=1;
    for(int i=2;i<=n;i++){
        while(a[i]-a[p]>k){
            p++;
        }
        for(int j=p;j<i;j++){
            fuck[j].push_back(i);
        }
    }
}

int dist[5005],cnt[5005];
void bfs(int st){
    queue<int> q;
    q.push(st);
    while(q.size()){
        int u = q.front();
        for(int v:fuck[u]){
            if(dist[v]==inf){
                dist[v] = dist[u] + 1;
                cnt[v] = 1;
                q.push(v);
            }else if(dist[v]==dist[u]+1){
                cnt[v]++;
                q.push(v);
            }
        }
        q.pop();
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ccc,T;
    cin>>ccc>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            fuck[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        init();
        int ans = 0;
        for(int st=1;st<=n;st++){
            for(int i=1;i<=n;i++){
                dist[i] = inf;
                cnt[i] = 0;
            }
            dist[st] = 0;
            bfs(st);
            for(int i=1;i<=n;i++){
                if(cnt[i]==2){
                    ans++;
                }
            }
            // cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
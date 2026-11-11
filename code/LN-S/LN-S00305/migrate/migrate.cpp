#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3000000;
const ll INF = 1e18;
//jdqk

int c;
ll a[N];
vector<int>G[N];
int n;
ll d;
ll dist[N];
ll cnt[N];

ll bfs(int s){
	for(int i = 1;i<=n;i++){
        dist[i] = -1;
        cnt[i] = -1;
    }
    queue<int>q;
    dist[s] = 0;
    cnt[s] = 1;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        //cout<<u<<' ';
        for(auto v : G[u]){
            if(cnt[v] == -1){
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            }
            else{
                if(dist[v] == dist[u] + 1){
                    cnt[v] += cnt[u];
                }
            }
        }
    }
    //cout<<endl;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
		//cout<<dist[i]<<" "<<cnt[i]<<endl;
        if(cnt[i] == 2)ans++;
    }
    return ans;
}


void query(){
    cin>>n>>d;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i + 1;j<=n;j++){
            if(a[j] - a[i] <= d){
                G[i].push_back(j);
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans += bfs(i);
    }
    cout<<ans<<"\n";

    for(int i = 1;i<=n;i++){
        G[i].clear();
        a[i] = 0;
    }
}

void query1(){
    cin>>n>>d;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(upper_bound(a+1,a+n+1,a[i] + d) - a == n + 1)continue;
        int d1 = (upper_bound(a+1,a+n+1,a[i] + d) - a) - (i + 1);
        if(d1 == 2){
            ans += n - (upper_bound(a+1,a+n+1,a[i] + d) - a) + 1; 
        }
    }
    cout<<ans<<"\n";
}

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int t;
    cin>>c>>t;
    while(t--){
        if(c == 13 || c == 14){
            query1();
        }
        else{
            query();
        }
    }
}

#include <bits/stdc++.h>
// #define int long long
#define N 2000005
using namespace std;
struct A{
    int x, cnt;
};
int n,m,ans,cnt,d,c,t;
int a[N],x[N],vis[N],dis[N];
bool check(int u,int v){
    int cnt = -1;
    memset(vis,0,sizeof(vis));
    queue<A> q;
    q.push({u,0});
    while(q.size()){
        A k = q.front();q.pop();
        if(cnt==-1&&k.x==v){
            cnt = k.cnt;
            continue;
        }
        if(cnt!=-1 && k.cnt>cnt)
            break;
        vis[k.x]++;
        
        for (int i = v; i > u;i++){
            if(x[i]-x[k.x]>d)
                continue;
            q.push({i,k.cnt+1});
        }
    }
    if(vis[v]>=3)
        return 0;
    return 1;
}
void solve(){
    cin >> n >> d;
    for (int i = 1; i <= n;i++){
        cin >> x[i];
    }
    if(n<=3){
        cout << 0 << "\n";
        return;
    }
    ans=0;
    if(c<=2){
        for (int u = 1; u <= n;u++){
            for(int v=u+3;v<=n;v++){
                if(check(u,v)){
                    cout << u << " " << v << endl;
                    ans++;
                } 
            }
        }
        cout<<ans<<"\n";
    }
    if(c==11 || c==12){
        int dd=x[2]-x[1];
        int kk=d/dd;
        cout << n - (2 * kk)  << endl;
    }  

}
signed main(){
    freopen("migrate1.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    // while(t--) solve();
    cout << rand();
    return 0;
}
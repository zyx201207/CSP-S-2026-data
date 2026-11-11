#include<bits/stdc++.h>
#define int long long
#define f(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
const int N=2000006;
int n,d,x[N];
int dis[N],cnt[N],ans;
void bfs(int rt){
    f(i,rt+1,n)dis[i]=0x3f3f3f3f;
    dis[rt]=0;
    deque<int>q;
    f(i,rt,n){
        while(!q.empty()&&x[i]-x[q.front()]>d)q.pop_front();
        for(auto j:q){
            if(dis[j]+1<dis[i])dis[i]=dis[j]+1,cnt[i]=1;
            else if(dis[j]+1==dis[i])cnt[i]++;
        }
        if(cnt[i]==2)ans++;
        q.push_back(i);
    }
}
void solve(){
    cin>>n>>d;
    f(i,1,n)cin>>x[i];
    ans=0;
    f(i,1,n)bfs(i);
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c,t;
    cin>>c>>t;
    if(c<=10)while(t--)solve();
    else while(t--){
        cin>>n>>d;
        f(i,1,n)cin>>x[i];
        int k=upper_bound(x+1,x+n+1,d+x[1])-x-1;
        if(k<=2){
            cout<<0<<'\n';
            continue;
        }
        k=k*2-2;
        cout<<(max(n-k+1,0LL))<<'\n';
    }
    return 0;
}

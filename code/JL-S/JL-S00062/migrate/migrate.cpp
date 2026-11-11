#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>g[2000010];
ll ans=0,len=0x3f3f3f3f;
int bfs(int s,int t){
    queue<pair<ll,ll> >q;
    q.push({s,0});
    while(!q.empty()){
        pair<ll,ll>x=q.front();
        q.pop();
        if(x.first==t){
            len=min(len,x.second);
            if(x.second==len) ans++;
            if(ans>2) return 0;
            for(auto i:g[x.first]){
                q.push({i,x.second+1});
            }
        }
    }
    if(ans==2) return 1;
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    ll n,d,a[2000010];
    cin>>c>>t;
    ll cnt=0;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<i;j++){
                if(abs(a[j]-a[i])<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
            for(int i=2;i<=n;i++){
                for(int j=1;j<i;j++){
                    if(bfs(j,i)) cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        cnt=0;
        for(int i=1;i<=n;i++) g[i].clear();
    }
}

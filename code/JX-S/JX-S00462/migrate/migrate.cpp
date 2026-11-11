#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,d;
ll l[2000005];
int bfs(ll s,ll t){
    queue<pair<ll,ll>> q;
    q.push({s,0});
    ll cnt=0,mn=1e9;
    while(!q.empty()){
        ll u=q.front().first;
        ll st=q.front().second;
        q.pop();
        if(u==t){
            if(cnt==0){
                cnt=1,mn=st;
                continue;
            }else{
                if(st==mn){
                    cnt++;
                    if(cnt>2) return 3;
                }else break;
            }
        }
        if(st>=mn) break;
        for(int i=u+1;i<=t;i++){
            if(l[i]-l[u]<=d&&st+1<=mn) q.push({i,st+1});
            else break;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>l[i];
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                if(bfs(i,j)==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
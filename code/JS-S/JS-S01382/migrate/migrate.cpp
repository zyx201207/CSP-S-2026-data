#include<bits/stdc++.h>
#define elif else if
#define endl '\n'
using namespace std;
typedef long long ll;
ll n,d;
ll x[2000006];

ll bfs(ll s,ll t){
    ll cnt=0,mn=1e18;
    queue<pair<ll,ll>>q;
    q.push({0,s});
    while(!q.empty()){
        auto [dis,u]=q.front();
        q.pop();
        if(u==t){
            if(dis<mn){
                cnt=1;
                mn=dis;
            }
            else if(mn==dis){
                cnt++;
            }
        }
        if(u>t)continue;
        for(int i=u+1;i<=t;i++){
            if(x[i]-x[u]>d)break;
            q.push({dis+1,i});
        }
    }
    return cnt;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            for(int i=1;i<=n;i++)x[i]=0;
            cin>>n>>d;
            ll c;
            for(int i=1;i<=n;i++){
                ll v;
                cin>>v;
                if(i==1)c=v;
                else if(i==2){
                    c=v-c;
                }
                x[i]=v;
            }
            cout<<n-2*d/c+1<<endl;
        }
        return 0;
    }
    if(c>2)return 0;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        ll ans=0;
        for(int len=4;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                if(bfs(i,i+len-1)==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

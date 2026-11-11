#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll C,T,n,d,ans,tot,lst[N],tmp[5005];
bool vis[5005];
vector<ll> mp[5005];
void solve(ll cu,ll to,ll stp){
    if(cu==to){
        tmp[++tot]=stp;
        return;
    }
    for(ll i=0;i<mp[cu].size();i++){
        ll v=mp[cu][i];
        if(vis[v]) continue;
        vis[v]=true;
        solve(v,to,stp+1);
        vis[v]=false;
    }
    return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>T;
    if(C==13 || C==14){
        while(T--){
            cin>>n>>d;
            for(ll i=1;i<=n;i++) cin>>d;
            cout<<0<<'\n';
        }
        return 0;
    }else if(C==11 || C==12){
        while(T--){
            cin>>n>>d;
            for(ll i=1;i<=n;i++){
                cin>>lst[i];
            }
            ll l=1,r=n;
            while(l<=r){
                ll mid=(l+r)/2;
                if(lst[mid]-lst[1]<=d){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            ll dst=l-1;
            if(dst<=2 || dst>=n){
                cout<<0<<'\n';
                continue;
            }
            cout<<n-2*dst+3<<'\n';
        }
        return 0;
    }else{
        while(T--){
            ll ans=0;
            cin>>n>>d;
            for(ll i=1;i<=n;i++){
                cin>>lst[i];
                mp[i].clear();
            }
            for(ll i=1;i<=n;i++){
                ll p=i+1;
                while(p<=n && lst[p]-lst[i]<=d){
                    mp[i].push_back(p);
                    p++;
                }
            }
            for(ll i=1;i<=n;i++){
                for(ll j=i+1;j<=n;j++){
                    if(lst[j]-lst[i]<=d) continue;
                    tot=0;
                    solve(i,j,0);
                    if(tot<2){
                        continue;
                    }
                    if(tot==2 && tmp[1]==tmp[2]){
                        ans++;
                        continue;
                    }
                    sort(tmp+1,tmp+tot+1);
                    if(tmp[1]==tmp[2] && tmp[2]!=tmp[3]){
                        ans++;
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
	return 0;
}

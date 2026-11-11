#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
ll c,t,n,d,x[N],cnt,ans;
vector<ll> e[N];
bool vis[N];
void path(ll fst,ll lst){
	if(fst==lst){
	    cnt++;
		return ;
	}
	for(ll v : e[fst]){
		vis[v]=1;
		path(v,lst);
		vis[v]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>x[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=1;k<=n;k++) vis[k]=0;
				cnt=0;
				vis[i]=1;
				path(i,j);
				if(cnt==2) ans++;
			}
		}
	    cout<<ans<<'\n';
	}
	return 0;
} 

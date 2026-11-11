#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll c,n,m,d,q,w[N],k,a1,t1,id1,id2,ans=0;
vector<ll> a[110],t[110];
inline void dfs(ll idx1,ll idx2){
	ll start,end;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<a[i].size();j++){
			if(a[i][j]==idx1){
				start=j+1;
				ans+=t[i][j];
				break;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<a[i].size();j++){
			if(a[i][j]==idx2){
				ans+=t[i][j];
				break;
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
		}
	}
	while(q--){
		ans=0;
		cin>>id1>>id2;
		dfs(id1,id2);
		ans+=(w[id1]+w[id2]);
		cout<<ans<<'\n';
	}
	return 0;
}

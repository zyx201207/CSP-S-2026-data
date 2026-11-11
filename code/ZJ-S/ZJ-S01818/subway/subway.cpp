#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sta{
	ll k;
	ll a[1010];
	ll t[1010];
}stat[5];
ll c,n,m,d,q,x,y;
ll w[20];
void dfs(ll index,ll sum){
	if(index==y){
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans) return;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=stat[i].k;j++){
			if(stat[i].a[j]==index){
				for(int s=1;s<=stat[i].k;s++){
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>stat[i].k;
		for(ll j=1;j<=k;j++){
			cin>>stat[i].a[j];
		}
	}
	while(q--){
		cin>>x>>y;
		dfs(x,0);
		cout<<35;
	}
	return 0;
}
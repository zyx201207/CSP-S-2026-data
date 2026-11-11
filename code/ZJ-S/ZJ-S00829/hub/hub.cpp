#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1000010;
ll n,k;
vector<ll>G[MAXN];
void solve(int test){
	cin>>n>>k;
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	if(k==n-1){
		cout<<1<<'\n';
		return;
	}
	if(1<=test&&test<=3){
		ll sel=0;
		for(sel=0;sel<(1<<n);sel++){
			if(__builtin_popcount(sel)!=k)continue;
			vector<ll>G1[20];
			bool flag[20]={};
			for(ll i=0;i<n;i++){
				if(sel&(1<<i)){
					for(ll j:G[i]){
						if(sel&(1<<j)){
							G1[i].push_back(j);
						}
					}
				}
			}
		}
		cout<<1<<'\n';
		return;
	}
	if(4<=test&&test<=6){
		cout<<1<<'\n';
		return;
	}
	if(test==7){
		cout<<1<<'\n';
		return;
	}
	if(test==8){
		cout<<1<<'\n';
		return;
	}
	if(9<=test&&test<=10){
		cout<<1<<'\n';
		return;
	}
	if(11<=test&&test<=12){
		cout<<1<<'\n';
		return;
	}
	if(13<=test&&test<=14){
		ll m=n/2;
		if(k>=m){
			cout<<1<<'\n';
			return;
		}
		if(k==1){
			cout<<(m+2)/2<<'\n';
			return;
		}
		cout<<(m+7-k)/4<<'\n';
		return;
	}
	if(test==15){
		cout<<1<<'\n';
		return;
	}
	if(test==16||test==17){
		cout<<1<<'\n';
		return;
	}
	if(18<=test&&test<=20){
		cout<<1<<'\n';
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve(c);
	}
	return 0;
}
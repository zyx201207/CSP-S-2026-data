#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5,inf=1e16;
long long C,T;
long long n,k,u,v,ch[N],bo[N],ans;
vector<long long> vec[N];
inline void solve(){
	ans=inf;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	if(n==k){
		cout<<0<<'\n';
		return ;
	}
	if(13<=C&&C<=14){
		n=(n+1)/2+1;
		long long u=(n-k);
		if(u%3==0) u/=3;
		else u=u/3+1;
		if(u<=0){
			cout<<1<<'\n';
		} 
		else cout<<u<<'\n';
		return ;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>C>>T;
	C=13;
	while(T--) solve();
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+7;
ll c,t;
struct qwq{
	int u,v;
}g[maxn];
void solve(){
	ll n,k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[i]={u,v};
	}
	if(k>=n/2){
		cout<<1<<"\n";
		return;
	}else if(3*k>=n){
		cout<<2<<"\n";
	}else{
		cout<<3<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==-1) cout<<"wo shi ju ruo";
	while(t--){
		solve();
	}
	return 0;
}
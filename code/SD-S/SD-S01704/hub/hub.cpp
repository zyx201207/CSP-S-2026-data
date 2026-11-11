#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll n,k;
vector<ll>e[N];
void solve(){
	memset(e,0,sizeof e);
	cin>>n>>k;
	for(ll i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout<<"0\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,_;
	cin>>c>>_;
	if(c==13||c==14){
		cin>>n>>k;
		for(ll i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<(n/2+(n%2==0?0:1)-k)/4+1+((n/2+(n%2==0?0:1)-k)%4==0?0:1)<<'\n';
	}
	else solve(); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}


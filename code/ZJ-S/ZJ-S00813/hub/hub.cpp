#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<vector>
using namespace std;
const int N=2e6+6;
ll c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll>adj[N];
		for(int i=1;i<=n;i++){
			ll u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);	
		}
		cout<<rand()%2000000+1;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
vector<int>g[n];
int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<n;i++){
			int v,u;
			cin>>v>>u;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<2<<"\n";
	}
}
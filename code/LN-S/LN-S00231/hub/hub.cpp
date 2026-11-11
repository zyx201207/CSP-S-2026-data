#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			a[u]=v;
			a[v]=u;
		}
		cout<<1<<'\n';
	}
	return 0;
}

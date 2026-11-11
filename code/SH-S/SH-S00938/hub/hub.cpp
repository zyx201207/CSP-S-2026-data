#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> a[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		cout<<(n+1)/2<<"\n";
	}
	return 0;
}

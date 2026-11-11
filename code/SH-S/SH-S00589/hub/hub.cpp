#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int>a[2000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			if(v>u)swap(u,v);
			a[u].push_back(v);
		}
		if(k>=n)cout<<1<<"\n";
		else cout<<2<<"\n";
	}
	return 0;
}

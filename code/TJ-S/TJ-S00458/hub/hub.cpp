#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k,maxu=-1,maxv=-1;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			maxu=max(maxu,u);
			maxv=max(maxv,v);
		}
		cout<<maxu<<" "<<maxv;
	}
	return 0;
}


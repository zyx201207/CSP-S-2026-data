#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		int m=(n-1)/2,mid=(1+m)/2;
		cout<<(mid-(1+mid)/2-k/4)+1<<"\n";
	}
	return 0;
}

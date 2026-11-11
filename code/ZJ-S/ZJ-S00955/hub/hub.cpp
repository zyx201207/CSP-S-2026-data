#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>c>>t;
	int k=t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<k-t+1;
	}
	return 0;
}

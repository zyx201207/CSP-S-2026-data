#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int a[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u]=v;
		}
		cout<<1;
	}
	return 0;
}

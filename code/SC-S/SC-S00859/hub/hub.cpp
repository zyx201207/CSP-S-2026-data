#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	int c,t,u[10000],v[10000];
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=2;i<=n;i++) cin>>u[i]>>v[i];
		cout<<abs(u[1]-v[1]);
	}
	return 0;
}
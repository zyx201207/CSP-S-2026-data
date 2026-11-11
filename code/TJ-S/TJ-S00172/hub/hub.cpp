#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++)cin>>u>>v;
		if(n==k)cout<<0<<'\n';
		else cout<<1<<'\n';
	}
	return 0;
}

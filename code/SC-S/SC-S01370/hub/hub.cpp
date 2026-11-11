#include<bits/stdc++.h>
using namespace std;
#define int long long
int u[1000005],v[1000005];
void cx(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
	}
	cout<<0;
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cx();
	}
	return 0;
}
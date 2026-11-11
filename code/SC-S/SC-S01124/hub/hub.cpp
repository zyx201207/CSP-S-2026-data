#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,mx[4005][4005][2][2];
vector<int> a[1000005];
//int dp(int r){
//	for(int i=0;i<r.size();i++){
//		dp(a[r][i]);
//		mx[r][1]=1;
//		for(int j=1;j<=)
//	}
//	return 0;
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			a[v].push_back(u);
			a[u].push_back(v);
		}
		if(k<=2){
			if(k==1){
				cout<<1<<'\n';
				continue;
			}
			if(n>2){
				cout<<1<<'\n';	
			}else{
				cout<<2<<'\n';
			}
			continue;
		}
//		dp(1);
	}
	return 0;
}
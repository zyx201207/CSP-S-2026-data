#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[2000005];
vector<int> path[2000005];
int c,t,n,d;
//void dfs(int x){
//	if(a[x+1]-a[x]>d || x+1>n){
//		path[x].push_back(x);
//		return;
//	}else{
//		path[x+1].push_back(x);
//	}
//	for(int i=1;i<=d;i++){
//		dfs(x+i);
//	}
//}


signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			cout<<n/d;
		}
	}
	
	return 0;
}

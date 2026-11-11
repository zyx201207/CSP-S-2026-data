#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,ans=0,b[1000005];
vector<int>ve[1000005];
void dfs(int x,int y,int z){
	if(y==m){
		if(z<=2){
			ans++;
		}
	}
	for(auto p:ve[x]){
		if(!b[p]){
			continue;
		}
		dfs(p,y,z);
		dfs(p,y+1,z+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			ve[x].push_back(y);
			ve[y].push_back(x);
		}
		dfs(1,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

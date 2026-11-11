#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000005];
int sd(int x,int fa){
	int ans=1;
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]==fa){
			continue;
		}
		ans=max(ans,sd(v[x][i],x)+1);
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ans=INT_MAX;
		for(int i=1;i<=n;i++){
			ans=min(ans,sd(i,0)-k/(int)v[i].size());
		}
		cout<<ans<<endl;
	}
	return 0;
}

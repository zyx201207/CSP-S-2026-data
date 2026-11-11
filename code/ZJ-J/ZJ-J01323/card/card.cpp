#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],vis[300010],f[500010];
vector<int> mp[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!vis[a[i]]) vis[a[i]]=i;
		mp[a[i]].push_back(i);
	}
	f[1]=1;
	ans[a[1]]++;
	for(int i=2;i<=n;i++){
		f[i]=1;
		if(vis[a[i-1]]==i-1){
			for(auto &j:mp[a[i-1]]) f[i]+=f[j];
		}
		ans[a[i]]+=f[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
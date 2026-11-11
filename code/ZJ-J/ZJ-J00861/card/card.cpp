#include<bits/stdc++.h>
using namespace std;
long long n,m,a[522222],la[522222],ans[522222],v[522222];
vector<long long>g[522222];
int dfs(int nw){
	int sum=0,ff=v[a[nw]];
	for(int i=0;i<g[nw].size();i++){
		if(ff==0)v[a[nw]]=1;
		sum+=dfs(g[nw][i]);
		if(ff==0)v[a[nw]]=0;
	}
	if(v[a[nw]]==0)ans[a[nw]]+=sum+1;
	return sum+1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(la[a[i]]==0)la[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(la[a[i]]==i)g[i+1].push_back(i);
		else g[la[a[i]]].push_back(i);
	}
	dfs(n);
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
/*AK!!AC!!*/
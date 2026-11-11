#include<bits/stdc++.h>
using namespace std;
int a[600001],n,m,last[600001],l[600001],sum=0,vis[600001],ans[600001];
void d(int x,int s){
	if(x==n+1)return;
	ans[a[x]]+=s;
	if(vis[x]==1){
		d(l[x]+1,s);
	}
	else{
		d(l[x]+1,s+1);
	}
	vis[x]=1;
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=n; i>=1; i--){
		if(last[a[i]]==0){
			last[a[i]]=i;
		}
		l[i]=last[a[i]];
	}
	for(int i=1; i<=n; i++){
		ans[a[i]]++;
		if(vis[i]==1)continue;
		d(i,0);
	}
	for(int i=1; i<=m; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
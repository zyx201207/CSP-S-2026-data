#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001],vis[200001];
int sum;int ans=-1;
void dfs(int pos){
	if(pos==m+1);
	{
		ans=max(sum,ans);
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int last=sum;
			vis[i]=1; 
			if(pos==1)sum=a[i];
			else sum&=a[i];
			dfs(pos+1);
			vis[i]=0;sum=last;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}


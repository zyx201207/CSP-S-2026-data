#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long ans;
int n,m;
void dfs(int dis,int g,long long sum){
	if(g==m){
		ans=max(ans,sum);
		return ;
	}
	for(int i=dis;i<=n;i++){
		int x=sum&a[i];
		dfs(i+1,g+1,sum&a[i]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int q=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			q=a[i];
			continue;
		}
		q=q&a[i];
	}
	if(m==n-1){
		int ans=INT_MIN;
		for(int i=1;i<=n;i++){
			ans=max(q&a[i],ans);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i+1,1,a[i]);
	}
	cout<<ans;
	return 0;
}

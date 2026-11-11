#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxn=-1,maxnb=-1;
long long a[200010], p[200010];
bool vis[200010];
void dfs(int step,int num){
	if(step==m+1)
	{
		long long k=p[1];
		for(int i=2;i<=m;i++){
			k&=p[i];
		}
		maxn=max(maxn,k);
	}
	for(int i=num;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			p[step]=a[i];
			dfs(step+1,i+1);
			vis[i]=0;
			p[step]=0;
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
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	else dfs(1,1);
	cout<<maxn;
	return 0;
}

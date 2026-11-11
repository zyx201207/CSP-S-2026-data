#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],__log[40],r[N],b[N];
int __ans(){
	int ans=__log[30];
	for(int i=1;i<=m;i++)
		ans&=a[r[i]];
	return ans;
}
void cut(int k){
	n=k;
	for(int i=1;i<=k;i++){
		a[i]=a[r[i]];
		b[i]=b[r[i]];
	}
}
int dfs(int x,int k){
	if(k==0)
		return a[x];
	int sum=0;
	for(int i=x+1;i<=n-k+1;i++)
		sum=max(sum,dfs(i,k-1));
	return sum&a[x];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	__log[0]=1;
	for(int i=1;i<=31;i++)
		__log[i]=__log[i-1]*2;
	for(int i=30;i>=n;i--){
		memset(r,0,sizeof(r));
		int k=0;
		for(int j=1;j<=n;j++)
			if(b[j]/__log[i]!=0)
				r[++k]=j;
		for(int j=1;j<=k;j++)
			b[r[j]]%=__log[i];
		if(k==m){
			cout<<__ans();
			return 0;
		}
		else if(k>m){
			cut(k);
		}
	}
	int ans=0;
	for(int i=1;i<=n-m+1;i++)
		ans=max(ans,dfs(i,m-1));
	cout<<ans;
	return 0;
}

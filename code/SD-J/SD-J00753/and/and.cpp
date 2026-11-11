#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,res;
int a[N],d[N];
bool f[N];
void dfs(int k,int lst,int ans){
	if(k==m){
		res=max(res,ans);
		return;
	}
	for(int i=lst;i<=n;i++){
		if(f[i])continue;
		f[i]=1;
		if(k==0)dfs(k+1,i,a[i]);
		else dfs(k+1,i,ans&a[i]);
		f[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0);
	cout<<res;
//	for(int i=1;i<=n;i++){
//		for(int j=m;j>=1;j--){
//			if(j==1)d[j]=a[i];
//			else d[j]=max(d[j],d[j-1]&a[i]);
//		}
//	}
//	cout<<d[m];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[200005];
//bool k[200005][31]={0};
bool vis[200005]={0};
long long f[200005];
long long mx=0;
int n,m;
void dfs(int x,long long ans){
	if(x==0){
		mx=max(ans,mx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x-1,ans&a[i]);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(f,-10,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		long long f=pow(2,31);
//		while(f/=2){
//			if(a[i]>=f){
//				a[i]-=f;
//			}
//		}
	}
	dfs(m,2147483647);
	cout<<mx;
	return 0;
}

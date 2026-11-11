#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
int n,m,a[N],ans;
void dfs(int x,int z,int f){
	if(x==0) ans=max(ans,z);
	for(int i=f+1;i<=n;i++){
		if(z==-1) dfs(x-1,a[i],i);
		else dfs(x-1,z&a[i],i);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	 }
	sort(a+1,a+1+n);
	if(m==1){
		 cout<<a[n];
		 return 0;
	 }
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		dfs(m,-1,0);
		cout<<ans;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}

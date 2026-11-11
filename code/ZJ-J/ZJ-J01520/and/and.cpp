#include<bits/stdc++.h>
using namespace std;
long long m,n,a[110000],mx=-1;
bool f[110000];
void dfs(long long k,long long ands){
	if(k==m){
		mx=max(mx,ands);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			dfs(k+1,ands&a[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		f[i]=0;
	}
//	sort(a+1,a+1+n);
//	long long ans=a[n];
//	for(long long i=n-1;i>=n-m+1;i--){
//		ans=ans&a[i];
//	}
//	cout<<ans;
	for(long long i=1;i<=n;i++){
		f[i]=1;
		dfs(1,a[i]);
		f[i]=0;
	}
	cout<<mx;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
//&
int n,m;
long long ans;
const int N=2e5+10;
long long f[N],a[N];
void dfs(long long x,int cnt,int op) {
	if(cnt==m) {
		ans=max(ans,x);
		cout<<x<<"\n";
	}
	for(int i=op; i<=n; i++) {
		dfs(x&a[i],cnt+1,i+1);
		dfs(x,cnt,i+1);
		dfs(a[i],1,i+1);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==1){
		long long anss=0;
		for(int i=1;i<=n;i++){
			anss=max(anss,a[i]);
		}
		cout<<anss;
		return 0;
	}
	if(m==2){
		long long anss=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				anss=max(anss,a[i]&a[j]);
			}
		}
		cout<<anss;
		return 0;
	}
	if(m==n){
		long long anss=a[1];
		for(int i=2;i<=n;i++){
			anss=anss&a[i];
		}
		cout<<anss;
		return 0;
	}
	dfs(0,1,1);
	cout<<ans;
//	f[1];=a[1];
//	for(int i=2;i<=n;i++){
//		for(int j=m;j>=1;j--){
//			long long sum=f[j-1]&a[i];
//			cout<<f[j-1]<<" "<<a[i]<<"\n";
//			f[i]=max(f[i-1],sum);
//			//f[i]=max(f[i],f[j-1]);
//		}
//	}
//	cout<<f[m];
	return 0;
}

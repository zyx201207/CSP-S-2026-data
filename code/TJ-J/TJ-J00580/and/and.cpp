#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,a[200000];
	cin>>n>>m;
	if(m==1){
		long long maxm=0;
		for(long long i=0;i<n;++i) {
			cin>>a[i];
			maxm=max(maxm,a[i]);
		}
		cout<<maxm;
		return 0;
	}
	if(m==n){
		long long ans;
		cin>>ans;
		for(long long i=1;i<n;++i){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2) {
		long long ans=0;
		for(long long i=0;i<n;++i) cin>>a[i];
		for(long long i=0;i<n;++i) {
			for(long long j=i+1;j<n;++j){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long maxm=0;
		for(long long i=0;i<n;++i){
			long long ans,cant;
			if(i==0) ans=a[1],cant=1;
			else ans=a[0],cant=0;
			for(long long j=0;j<n;++j){
				if(j!=i&&j!=cant) ans&=a[j];
			}
			maxm=max(maxm,ans);
		}
		cout<<maxm;
		return 0;
	}
	cout<<0;
}

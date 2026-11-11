#include<bits/stdc++.h>
using namespace std;

long long n,m;
const long long N=2e5;
const long long W=30;
long long a[N+5];
long long r[N+5][W+5];
bool vis[N+5];
long long ans=0;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		long long at=a[i];
		for(long long j=0; j<=30; j++) {
			if(at&1) r[i][j]=1;
			else r[i][j]=0;
			at>>=1LL;
		}
	}
	/*
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=10;j++) cout<<r[i][j];
		cout<<endl;
	}
	*/
	for(long long i=30; i>=0; i--) {
		long long cnt=0;
		for(long long j=1; j<=n; j++) {
			if(r[j][i]==1&&(!vis[j])) cnt++;
		}
//		cout<<cnt<<endl;
		if(cnt>=m) {
			ans+=(1LL<<i);
			for(long long j=1; j<=n; j++) {
				if(r[j][i]==0) vis[j]=true;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

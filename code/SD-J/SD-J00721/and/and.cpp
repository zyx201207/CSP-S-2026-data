#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],k[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) k[i]=a[i];
	sort(k+1,k+n+1);
	bool o=1;
	for(int i=1;i<=n;++i) if(((a[i]+1)&a[i]!=0)) o=0;
	bool e=1;
	for(int i=1;i<=n;++i) if(a[i]!=i-1) e=0;
	if(m==1){
		int Max=-1e15;
		for(int i=1;i<=n;++i) Max=max(Max,a[i]);
		cout<<Max;
		return 0; 
	}
	if(m==n){
		int k=a[1];
		for(int i=2;i<=n;++i) k=k&a[i];
		cout<<k;
		return 0;
	}
	if(m==2){
		int ans=-0x3f3f3f3f;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int l=k[2];
		for(int i=3;i<=n;++i) l=l&k[i];
		cout<<l;
	}
	if(o){
		int res=k[n];
		for(int i=n-1;i>=n-m+1;i--) res=res&k[i];
		cout<<res;
		return 0;
	}
	if(e){
		int v=k[n];
		for(int i=n-1;i>=n-m;i--) v=v&k[i];
		cout<<v;
		return 0;
	}
	sort(a+1,a+n+1);
	int z=k[n];
	for(int i=n-1;i>=n-m;i--) z=z&k[i];
	cout<<z;
	return 0;
}


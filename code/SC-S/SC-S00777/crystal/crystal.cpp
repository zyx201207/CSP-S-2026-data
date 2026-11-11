#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],d[N],t[N],f[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		t[i]=t[i-1]+d[i];
		s[i]=s[i-1]+t[i];
		f[i]=i*t[i]-s[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		int x=upper_bound(f+1,f+n+1,f[i]+m)-f;
		ans=max(x-i,ans);
	}
	cout<<ans<<endl;
	return 0;
}
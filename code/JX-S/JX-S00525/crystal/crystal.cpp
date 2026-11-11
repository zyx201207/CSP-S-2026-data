#include <bits/stdc++.h>
#define int long long
#define N 500003
using namespace std;
int n,m,a[N],s[N],ans[N],res;
int Bin_Found(int e,int x){
	int l=1,r=e;
	while(l<r){
		int mid=(l+r)>>1,tmp=(e-mid)*a[e]-s[e-1]+s[mid-1];
		if(tmp>m) l=mid+1;
		else r=mid;
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) ans[i]=i*a[i]-s[i];
	for(int i=1;i<=n;i++) res=max(i-Bin_Found(i,m)+1,res);
	cout<<res<<'\n';
	return 0;
}

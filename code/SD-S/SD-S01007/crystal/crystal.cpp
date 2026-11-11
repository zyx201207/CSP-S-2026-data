#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int n,m,a[N],f[N],an;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(f[i]-f[mid-1])<=m)ans=mid,r=mid-1;
			else l=mid+1;
		}
		an=max(an,i-ans+1);
	}
	cout<<an;
	return 0;
}
/*
Oct31==Dec25?
*/

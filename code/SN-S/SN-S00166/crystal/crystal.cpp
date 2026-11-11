#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],sum[N];
int solve(int x){
	int l=1,r=x,res=x;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(sum[x]-sum[mid-1])<=m) r=mid-1,res=mid;
		else l=mid+1;
	}return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i!=n&&a[i]==a[i+1]) continue;
		ans=max(ans,i-solve(i)+1);
	}cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+6;
int n,m,ans=1,a[maxn],sum[maxn];
bool check(int x){//x=4
	for(int i=1;i<=n-x+1;i++)
		if((x-1)*a[x+i-1]-sum[x+i-2]+sum[i-1]<=m) return 1;
		//i=2  3*a[4]-sum[3]+sum[0]
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}//15:37过T1 
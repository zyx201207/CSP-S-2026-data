#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m,a[N],d[N],dp[N],ans=0;
inline int get(int l,int r,int R){
	int res;
	if(l==r) return l;
	int mid=l+r>>1;
	if(dp[R]-dp[mid]-((mid-1)*(a[R]-a[mid]))>m) res=get(mid+1,r,R);
	else res=get(l,mid,R);
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int r=1;r<=n;r++){
		d[r]=a[r]-a[r-1];
		dp[r]=dp[r-1]+(r-1)*d[r];
		int l=get(1,r,r);
		ans=max(ans,r-l+1);
		//cout<<l<<' '<<r<<' '<<ans<<endl;
	}
	/*for(int i=1;i<=n;i++)	cout<<d[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++)	cout<<dp[i]<<' ';
	cout<<endl;*/
	cout<<ans;
	return 0;
} 

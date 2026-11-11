#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+15; 
int n,m;
int a[N],sum[N];
int ans;
bool check(int mid,int i){
	return a[i]*mid-(sum[i]-sum[i-mid])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid,i)) l=mid;
			else r=mid-1;
		}
		ans=max(ans,l);
	}
	cout<<ans<<'\n';
	return 0;
} 

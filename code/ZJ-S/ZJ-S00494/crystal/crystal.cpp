#include<bits/stdc++.h>
#define int long long
#define add(L,R) (sum[R]-sum[(L)-1])
using namespace std;
int a[500002],sum[500002];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n+1;++i){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;++i){
		int l=0,r=i-1;
		while(l<r){
			int mid=l+r+1>>1;
			if(a[i]*mid-add(i-mid,i-1)>m)r=mid-1;
			else l=mid;
		}
		ans=max(ans,l);
	}
	cout<<ans+1;
}
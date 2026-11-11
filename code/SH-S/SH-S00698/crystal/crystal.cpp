#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+3;
int a[maxn],sum[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,tmp=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]<=m+sum[i]-sum[mid-1]){
				tmp=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int a[N];
int n,m;
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ans=0;
	for (int i=1;i<=n;++i) cin>>a[i];
	stable_sort(a+1,a+1+n);
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;++i){
		int l=1,r=i,res=-1;
		while (l<=r){
			int mid=(l+r)/2;
			int len=(i-mid+1);
			int val=len*a[i];
			int tmp=sum[i]-sum[mid-1];
			if (val-tmp<=m){
				r=mid-1;
				res=max(res,len);
			}else l=mid+1;
		}
		ans=max(res,ans);
	}
	cout<<ans;
	return 0;
}

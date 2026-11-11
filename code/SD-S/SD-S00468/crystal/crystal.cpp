#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=((l+r)>>1);
			int need=a[i]*(i-mid)-(sum[i-1]-sum[mid-1]);
			if(need<=k)	ans=max(ans,i-mid+1),r=mid-1;
			else	l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=500010;
int n,m,mx;
ll a[N],sum[N];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		mx=max(mx,i-ans+1);
	}
	cout<<mx<<endl;
	return 0;
}

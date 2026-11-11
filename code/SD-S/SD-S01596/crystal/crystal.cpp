#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,sum[N];
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,pos=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				pos=mid;
			}else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}

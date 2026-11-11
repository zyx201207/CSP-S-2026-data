#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define pii pair<int,int>
#define ft first
#define sd second
#define db double
const int INF=1e18,N=5e5+5;
int n,m,a[N];
int qs[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	AC;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)qs[i]=qs[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,res=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(qs[i-1]-qs[mid-1]+m>=a[i]*(i-1-mid+1))r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	} 
	cout<<ans;
	return 0;
}


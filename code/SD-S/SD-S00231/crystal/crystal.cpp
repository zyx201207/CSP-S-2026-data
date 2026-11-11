#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=5e5+615;
int n,m,a[N],ans=1,s[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i,id=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-1-mid+1)-(s[i-1]-s[mid-1])<=m)r=mid-1,id=mid;
			else l=mid+1;
		}
		ans=max(ans,i-id+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
----------
5 8
-3 -1 2 2 7
*/

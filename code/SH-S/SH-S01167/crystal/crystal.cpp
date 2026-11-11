#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back

const int inf=1e18;
const int maxn=5e5+10;
int n,a[maxn],s[maxn],m,ans=0;

inline bool check(int l,int r){
	return a[r]*(r-l+1)-(s[r]-s[l-1])<=m;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i,mid=(l+r)>>1;
		while(r>l){
			if(check(mid,i)) r=mid;
			else l=mid+1;
			mid=(l+r)>>1;
		}
		ans=max(ans,i-mid+1);
	}
	cout<<ans<<"\n";
	return 0;
}



#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+5;
int n;
ll m;
ll a[maxn],s[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,t=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) t=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-t+1);
	}
	cout<<ans<<'\n';
	return 0;
}
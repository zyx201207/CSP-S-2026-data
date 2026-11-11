#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
int s[maxn],a[maxn],ans,m,n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int res=1;
		while(l<=r){
			int mid=((l+r)>>1);
			if(s[i]-s[i-mid]>=mid*a[i]-m){
				res=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,res);
//		cerr<<i<<' '<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}

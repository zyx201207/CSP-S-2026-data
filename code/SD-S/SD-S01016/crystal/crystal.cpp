#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N],ans,s[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]; 
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid=l+r>>1;
			int t=(i-mid+1)*a[i]-(s[i]-s[mid-1]);
			if(t<=m) r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<'\n';
	return 0;
}


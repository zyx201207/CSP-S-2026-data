#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int n,m;cin>>n>>m;
	vector<int>a(n+1,0),S(n+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		S[i]=S[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;int res=0;
		while(l<=r){
			int mid=l+r>>1;
			if((i-mid+1)*a[i]-(S[i]-S[mid-1])<=m){
				res=mid;r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<'\n';
	return 0;
}

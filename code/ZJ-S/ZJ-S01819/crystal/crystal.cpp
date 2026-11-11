#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1,a[500005],c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,cnt=i;
		while(l<=r){
			int mid=(l+r)/2;
			int energy=a[i]*(i-mid+1)-(c[i]-c[mid-1]);
			if(energy<=m){
				r=mid-1;
				cnt=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-cnt+1);
	}
	cout << ans << endl;
	return 0;
}

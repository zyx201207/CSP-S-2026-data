#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])>m)
				l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}

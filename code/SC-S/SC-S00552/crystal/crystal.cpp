#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,p=10000000;
		while(l<=r){
			mid=(l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)  r=mid-1,p=min(p,mid);
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
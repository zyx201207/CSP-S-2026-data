#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	int l=1,r=1,cur=0;
	sort(a+1,a+n+1);
	while(r<n){
		r++;
		cur+=(r-l)*(a[r]-a[r-1]);
		while(l<=r&&cur>m){
			cur-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
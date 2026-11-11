#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000010],f[1000010],sum;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(r<=n){
		while(sum<=m&&r<n) r++,sum+=(r-l)*(a[r]-a[r-1]);
//		cout<<l<<" "<<r<<" "<<sum<<endl;
		ans=max(r-l,ans);
		sum-=a[r]-a[l],l++;
		if(r==n) break;
	}
	cout<<ans;
	return 0;
}

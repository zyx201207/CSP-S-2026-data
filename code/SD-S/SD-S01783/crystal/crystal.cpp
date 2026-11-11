//AMANI NAKUPENDA NAKUPENDA WE WE
//TUNATAKA WE WE
//AMANI NAKUPENDA NAKUPENDA WE WE
#include<bits/stdc++.h>
using namespace std;
int n;long long m;
long long a[500005],s[500005];
long long su0(int l,int r){
	long long ans=0;
	for(int i=l;i<=r;++i)ans+=a[r]-a[i];
	return ans;
}
long long su1(int l,int r){
	long long ans=(r-l+1)*a[r]-(s[r]-s[l-1]);
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	int ans=0,r=0;
	for(int i=1;i<=n;++i){
		r=max(r,i);
		while(r<n&&su1(i,r+1)<=m)++r;
		ans=max(ans,r-i+1);
	}
	printf("%d\n",ans);
	return 0;
}

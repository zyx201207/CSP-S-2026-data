#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5+5;

int n;
ll m,a[N];
ll sum[N];

bool check(int l,int r){
	ll s=sum[r]-sum[l-1];
	s=a[r]*(r-l+1)-s;
	return s<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int r=1,ans=1;
	for(int l=1;l<=n;l++){
		while(r<=n&&check(l,r))
			++r;
		ans=max(ans,r-l);
	}
	printf("%d\n",ans);
	return 0;
}
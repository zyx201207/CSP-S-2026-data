//crychic.cpp
#include<bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,sum=0,ans=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		while(l<i&&a[i]*(i-l+1)-sum>m)sum-=a[l],l++;
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
/*
Haruhikage
*/
//Chihaya Anon
//MyGO!!!!!

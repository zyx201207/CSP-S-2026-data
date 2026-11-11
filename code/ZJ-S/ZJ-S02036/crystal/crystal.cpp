#include<bits/stdc++.h>
#define N 5000005
#define INF 0x3f3f3f3f3f3f3f3f
#define LL long long
using namespace std;
int n;
LL m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int j=1,ans=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(a[j+1]*(j-i+2)-s[j+1]+s[i-1]<=m&&j<=n)j++;
		ans=max(j-i+1,ans);
	}
	cout<<ans<<endl;
	return 0;
}

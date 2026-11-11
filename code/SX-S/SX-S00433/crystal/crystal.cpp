#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long m,a[N+5];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,ans=1;
	long long sum=0;
	for(int r=2;r<=n;r++){
		sum+=1ll*(r-l)*(a[r]-a[r-1]);
		while(sum>m) sum-=a[r]-a[l],l++;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	return 0;
}

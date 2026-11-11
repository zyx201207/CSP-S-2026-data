#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+50;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int sum=0,l=0,cnt=0,ans=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		while(sum>m&&l<=i){
			l++;cnt--;
			sum-=a[i]-a[l];
		}
		sum+=(i-l+1)*(a[i]-a[i-1]);
		cnt++;
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
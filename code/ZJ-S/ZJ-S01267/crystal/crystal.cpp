#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
const ll INF=2e16;
ll a[N],m,n,num,l,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	l=1;
	for(int i=2;i<=n;i++){
		num+=(i-l)*(a[i]-a[i-1]);
		while(l<=i&&num>m)num-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
} 

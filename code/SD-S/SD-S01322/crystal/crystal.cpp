#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n;
ll a[N],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll sum = 0;
	int ans = 1;
	for(int i = 1,j = 1;i<=n;i++){
		sum+=a[i];
		while((i-j+1)*a[i]-sum>m)sum-=a[j++];
		ans = max(ans,i-j+1);
	}
	printf("%d\n",ans);
	return 0;
}


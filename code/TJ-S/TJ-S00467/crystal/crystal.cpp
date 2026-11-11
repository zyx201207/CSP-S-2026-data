#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

#define N 500005
#define int long long

int n,m;
int a[N],b[N],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		b[i] = a[i];
	}
	sort(a + 1,a + n + 1);
	int l = 1,sum = 0;
	for(int r = 1;r <= n;r++){
		sum += (a[r] - a[l]) * (r - l);
		a[l] = a[r];
		while(sum > m){
			sum -= (a[l] - b[l]);
			a[l] = a[r];
			l++;
		}
		ans = max(r - l + 1,ans);
	}
	printf("%lld",ans);
	return 0;
}

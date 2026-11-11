#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
typedef long long LL;
int n;
LL m,a[N],b[N],ccf;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int l = 1,r = i,mid = 0,p = 0;
		while(l <= r){
			mid = (l + r) / 2;
			if(b[i - 1] - b[mid - 1] + m >= a[i] * (i - mid)){
				p = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(i - p + 1,ans);
	}
	printf("%d",ans);
	return 0;
}

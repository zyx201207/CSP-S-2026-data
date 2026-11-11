#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
int n,ans=0;
ll m,a[N],b[N];
int find(int bor,ll num){
	int l = 1,r = bor;
	while(l < r){
		int mid = (l+r)>>1;
		if(num*(bor-mid+1) - (b[bor]-b[mid-1]) <= m)
			r = mid;
		else
			l = mid+1;
//		printf("%lld %lld %lld %lld\n",num,num*(bor-mid+1),b[bor]-b[mid-1],mid);
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int st = 1;
	for(int i = 1;i <= n;i++){
		b[i] = b[i-1] + a[i];
		if(a[i] != a[i-1] || i == 1)	st = i;
		if(a[i] != a[i+1] || i == n){
			int pos = find(st,a[i]);
			ans = max(ans,i-pos+1);
//			printf("%d %d %d\n",pos,i,ans);
		}
	}
	printf("%d",ans);
	return 0;
}

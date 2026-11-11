#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef __int128 i28;
#define expr constexpr
#define db if(DEBUG)
#define ndb if(!DEBUG)
#define printf db printf
#define P pair<int,int>
#define F first
#define S second
#define DEBUG 0

expr int N = 5e5+5;
int n;
LL m;
LL a[N];
i28 s[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ndb ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans = 0;
	auto cost=[&](int l,int r) -> i28 {
		printf("--- sum[%d,%d] = %lld\n",l,r,LL(s[r]-s[l-1]));
		return (i28)(r-l+1)*a[r]-(s[r]-s[l-1]);
	};
	for(int i=1,j=1;i<=n;i++) {
		while(j<i && cost(j,i)>m) j++;
		printf(">>> cost[%d,%d] = %lld\n",j,i,(LL)cost(j,i));
		ans = max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*

*/
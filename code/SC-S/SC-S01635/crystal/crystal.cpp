#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

const int N=5e5+9;
ll n,m,a[N];
int f[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	priority_queue<int> q;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1;
	ll cost=0;
	f[1]=1;
	for(int r=2;r<=n;r++) {
		cost+=(r-l)*(a[r]-a[r-1]);
		while(r>l && cost>m) {
			cost-=a[r]-a[l];
			l++;
		}
		f[r]=r-l+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=ans>f[i]? ans:f[i];
	printf("%d\n",ans);
	return 0;
}
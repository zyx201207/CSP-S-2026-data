#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define test(x) cerr << "Test: " << (x) << '\n';
#define debug test("qwq")
#define pii pair<int,int>
#define eb emplace_back
#define F first
#define S second
typedef long long ll;
const int N = 2e6 + 19;
ll a[N],n,d,jump[N],R[N],jump2[N];
int t[N];
void solve() {
	scanf("%lld%lld",&n,&d);
	for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for (int i=1,j=1;i<=n;++i) { // debug;
		for (;j<n&&a[i]+d>=a[j+1];++j);
		jump[i]=j; // test(jump[i]);
		// test(j);
	} ll ans=0;
	for (int i=1,j=1;i<=n;++i) {
		for (;a[i]-a[j]>d;++j);
		jump2[i]=j;
	}
	vector<pii> chain;
	for (int i=1;i<=n;++i) {
		int j=jump[i],k=jump[j];
		if (i==j || j==k) {
			t[i]=0;
		} else {
			if (j==i+1 || jump[j-2]==jump[j-1]) t[i]=1;
			else if (j-i>1 && jump[j-2]==k) t[i]=3;
			else t[i]=2;
		} // test(t[i]);
		if (t[i]==2) chain.eb(i,k);
	} // debug;
	for (int i=1;i<=n;++i) {
		int j=jump[i],k=jump[j];
		if (i==j || j==k) {
			t[i]=0;
		} else {
			if (t[i]==1) continue;
			// if (t[i]>1) ans+=jump[j-1]-jump[j-2];
			int A=1,B=1,y=j-1;
			while (k!=n) {
				int to=jump[k];
				if (a[to]-a[k-1]<=d || t[y]==2) break;
				k=to; ++B; y=jump[y];
			}
			int x=i;
			// {
			// 	int u=jump2[x],v=jump2[u];
			// 	if (jump[u+1]!=i) flag=0;
			// }
			while (x>1) {
				int to=jump2[x];
				if (a[x+1]-a[to]<=d || t[to]==2) break;
				x=to; ++A;
			} // test(A);
			ans+=1LL*(A+B-1)*(jump[j-1]-jump[j-2]);
			ans+=1LL*(A-1)*(B-1);
			// printf("i=%d, A=%d,B=%d val=%lld, R=%lld\n",i,A,B,jump[j-1]-jump[j-2],jump[j]);
		} // test(ans);
		if (t[i]==2) chain.eb(i,k);
	} 
	printf("%lld\n",ans);
	// for (int i=1;i<(int)chain.size();++i) if (chain[i].F<chain[i-1].S&&chain[i].S>chain[i-1].S) debug;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tc,t;
	scanf("%d%d",&tc,&t);
	while (t--) solve();
	return 0;
}
/*
g++ A.cpp -o tmp &&./tmp
*/
/*
g++ A.cpp -o tmp &&./tmp
哥们尽力了，真不会做，写了三个小时，全假了，调试不出来，加训吧。。。。
*/
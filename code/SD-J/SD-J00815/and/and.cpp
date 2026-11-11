#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
map<int,int> mp;
int qpow(int a,int b) {
	int res=1;
	while (b) {
		if (b&1) res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
void init() {
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++)mp[a[i]]++;
}
int solve1(int x) {
	int ans=qpow(2,31)-1;
	for (int i=n; i>=(n-x+1); i--) ans&=a[i];
	return ans;
}
int solve2(int x) {
	int ans=qpow(2,31)-1;
	for (int k=n; k>=1; k--) {
		int i=a[k],j=mp[a[k]];
		if (j>=2) {
			ans&=i;
			x-=j;
			if (x<=0) {
				return ans;
			}
		}
	}
	if (x>0) {
		for (int k=n; k>=1; k--) {
			int i=a[k],j=mp[a[k]];
			if (j==1) {
				ans&=i;
				x-=j;
				if (!x) {
					return ans;
				}
			}
		}
	}
} 
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	init();
	cout<<max(solve1(m),solve2(m));
	return 0;
}
/*
5 3
31 3 1 15 7
期望得分：50~60
*/

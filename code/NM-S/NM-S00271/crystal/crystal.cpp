#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//#include<algorithm>
using namespace std;
const int N = 5e5+3;
typedef long long ll;

int n;
ll m;
ll a[N];
int cnt;
bool vis[N];
int maxcnt = 1;
int sum;
void dfs(int pos, ll t) {
	if(t<0)
		return ;
	maxcnt = max(maxcnt,cnt);
	cnt = 1;
	if(pos + 1 == n) {
		sum = abs(a[1]-a[n]);
		cnt += 2;
		return ;
	} else {
		sum = abs(a[pos]-a[pos + 1]);
		cnt += 2;
	}
	dfs(pos+1,t-sum);
}
//  abs(a[pos]-a[pos + add])
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	if(n == 1) {
		printf("1\n");
		return 0;
	} else if(n == 2) {
		if(abs(a[2] - a[1])<=m)
			printf("2\n");
		else
			printf("1\n");
			return 0;
	}

	sort(a+1,a+n+1);

	if(m == 0) {
		int cnttt = 1;
		for(int i=1; i<=n; i++) {
			if(a[i] == a[i + 1])
				cnttt++;
		}
		printf("%d", cnttt);
		return 0;
	}
	dfs(1,m);
	printf("%d", maxcnt);
	return 0;
}


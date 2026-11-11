#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	long long maxn = -1;
	for (int i = 1;i <= n;i++){
		int a1[500005];
		long long m1 = m,sum = 0,o = 0,j1 = 0;
		for (int j = 1;j <= n;j++){
			a1[j] = abs(a[j]-a[i]);
		}
		sort(a1+1,a1+n+1);
		while(m1 >= 0&&o<=n){
			if (o == i) {
				o++;
				continue;
			}
			sum++;
			m1-=a1[++o];
		}
		maxn = max(maxn,sum-1);
	}
	cout << maxn;
}


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5+78;
const int M = 3e5+91;

ll a[N];
ll b[N];
int ans[M];

int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		scanf("%lld",&a[i]);
	}
	//
	for (int i = 1;i <= n;i++) {
		int idx = 1;
		for (int j = i;j <= n;j++) {
			for (int k = 1;k <= idx;k++) {
				if (b[k] == a[j]) {
					idx = k;
					break;
				}
			}
			b[idx] = a[j];
			idx++;
		}
		idx--;
		for (int j = 1;j <= idx;j++) {
			ans[b[j]]++;
			b[j] = 0;
		}
		
	}
	//
	for (int i = 1;i <= m;i++) {
		printf("%d ",ans[i]);
	}
	
	return 0;
}

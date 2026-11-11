#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--) {
		int n,k;
		scanf("%d%d",n,k);
		int ans = n % k + 1;
		printf ("%d",ans);
	}
	
	return 0;
}	

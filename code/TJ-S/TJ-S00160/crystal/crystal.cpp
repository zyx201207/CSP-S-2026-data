#include <bits/stdc++.h>
using namespace std;

namespace z {

#define int long long
const int N = 5e5 + 5;
int n, m, a[N], s[N];
void main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a +1, a +n +1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans=0;
	for(int i = 1, j = 1; i <= n; i++) {
		while(j < i && (i - j + 1) *a[i]-(s[i] - s[j - 1])>m)
			j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}

#undef int 

}

int main() {
	z::main();
	return 0;
}


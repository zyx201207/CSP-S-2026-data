#include<cstdio> 
#include<iostream>
#include<algorithm> 
using namespace std;

const int N = 5e5 + 5;
long long a[N],s[N];
int n;
long long m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int i = 1;i <= n;i++) { // set a[i] as the base value
		int l = 1,r = i,num = 0;
		while (l <= r) {
			int mid = (l + r) >> 1; // ATTENTION, there might be a bug
			// mid means the position that the items in [mid,i] are all the same
			if ((1ll * (i - mid + 1) * a[i] - (s[i] - s[mid - 1])) <= m)
				r = mid - 1, num = mid;
			else l = mid + 1;
		}
		ans = max(ans,i - num + 1);
	}
	cout << ans << '\n';
	return 0;
}

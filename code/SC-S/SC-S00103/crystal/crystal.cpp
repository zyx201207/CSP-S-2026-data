#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL a[(int)5e+5+10];
bool hsh[(int)5e+5+10];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, i; LL m; cin>>n>>m; // Ten year OI will be gone if I don't use long long.
	for (i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+1+n);
	
	memset(hsh, false, sizeof(hsh));
	for (i=2; i<=n; i++) {
		if (a[i] == a[i-1]) continue;
		if (m==0) goto outend;
		while (a[i] != a[i-1]) {
			for (int j=i-1; j>=1; j--) {
				a[j]++, m--; hsh[j] = true; if (m==0) goto outend;
			}
		}
	}
	
	outend:
		;
	while (a[i] == a[i-1]) {hsh[i] = true; i++;}
	int cnt = 0;
	for (i=1; i<=n; i++) if (hsh[i] == true) cnt++;
	cout<<cnt;
	return 0;
}
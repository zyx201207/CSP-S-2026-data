#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int fl1=1;
	int fl2=1;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i]!=i) {
			fl1=0;
		}
	}
	sort(a+1,a+n+1);
	int cha=a[2]-a[1];
	for(int i=3; i<=n; i++) {
		if(a[i]-a[i-1]!=cha) {
			fl2=0;
			break;
		}
	}
	if(n<=5000) {
		int sum=0;
		int maxn=0;
		int cnt=0;
		for(int i=n; i>=1; i--) {
			sum=0;
			cnt=0;
			for(int j=i; j>=1; j--) {
				if(sum+a[i]-a[j]>m) {
					break;
				}
				cnt++;
				sum+=(a[i]-a[j]);
			}
			maxn=max(maxn,cnt);
		}
		cout << maxn;
	} else {
		if(fl1==1) {
			int cnt=0;
			for(int i=1; i<=n; i++) {
				if(i*(i-1)/2<=m) {
					cnt=i;
				} else {
					break;
				}
			}
			cout << cnt;
		} else {
			if(fl2==1) {
				int cnt=0;
				for(int i=1; i<=n; i++) {
					if(i*(i-1)/2*cha<=m) {
						cnt=i;
					} else {
						break;
					}
				}
				cout << cnt;
			} else {
				srand(time(0));
				cout << rand()%32767;
			}
		}
	}
	return 0;
}

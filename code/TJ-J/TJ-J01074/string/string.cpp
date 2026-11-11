#include<bits/stdc++.h>
using namespace std;
struct st{
	int i=0;
	char c;
};
st a[200005];
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int l=0,r=n-1;
	for (int j=0;j<n;j++) {
		cin >> a[j].i >> a[j].c;
	}
	while (l<r) {
		if (a[l].c!=a[r].c) ans+=min(a[l].i,a[r].i);
		if (a[l].i==a[r].i) {
			l++;
			r--;
		}
		else if (a[l].i<a[r].i) {
			a[r].i-=a[l].i;
			l++;
		}
		else if (a[l].i>a[r].i) {
			a[l].i-=a[r].i;
			r--;
		}
	}
	cout << ans;
	return 0;
}

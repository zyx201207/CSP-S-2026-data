#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ans[205],q[505];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	for (int i=0;i<n;i++) {
		map<int,int> ma;
		for (int j=i;j<n;j++) {
			q[j-i]=a[j];
		}
		for (int j=0;j<n-i;j++) {
			for (int k=j;k<n-i;k++) {
				if (q[j]==q[k]) {
					j=k;
					break;
				}
			}
			ans[q[j]]++;
		}
	}
	for (int i=0;i<m;i++) cout << ans[i] << ' ';
	return 0;
}

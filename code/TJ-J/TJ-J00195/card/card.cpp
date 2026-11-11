#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,a[50005],t[30005],sum[50005];
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int k=1; k<=n; k++) {
		for(int j=1; j<=m; j++) {
			t[j]=0;
		}
		for(int i=k; i<=n; i++) {
			if(t[a[i]]!=0) {
				for(int j=1; j<=m; j++) {
					t[j]=0;
				}
			}
			t[a[i]]++;
		}
		for(int j=1; j<=m; j++) {
			if(t[j]==1) {
				sum[j]++;
			}
		}

	}
	for(int j=1; j<=m; j++) {
		cout<<sum[j]<<" ";
	}
	return 0;
}

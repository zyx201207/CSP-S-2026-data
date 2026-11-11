#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010];
int cnt[300010];
bool tp[300010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++) {
		for(int j = i;j<=n;j++) {
			cnt[a[j]]++;
			if(b[a[j]] != 0) {
				for(int k = b[a[j]];k<j;k++) {
					if(tp[k]) {
						continue;
					}
					cnt[a[k]]--;
					tp[k] = true;
					if(b[a[k]] == k) {
						b[a[k]] = 0;
					}
				}
			}
			b[a[j]] = j;
		}
		for(int j = 1;j<=m;j++) {
			b[j] = 0;
		}
		for(int j = 1;j<=n;j++) {
			tp[j] = false;
		}
	}
	for(int i = 1;i<=m;i++) {
		cout<<cnt[i]<<" ";
	}
	return 0;
}

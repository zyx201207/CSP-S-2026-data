#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],t2[N]={0};
bool flagdz=true;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (i>=2&&a[i-1]>a[i]) flagdz=false;
	}
	if (flagdz) {
		int len=1;
		for (int i=1;i<=n;i++) {
			if (a[i]==len+1) {
				len++;
				cout << i-1 << " ";
			}
			if (a[i]>m) break;
		}
		if (a[n]==m) cout << n;
	} else {
		for (int i=1;i<=n;i++) {
			int t1[N];
			memset(t1,0,sizeof t1);
			for (int j=i;j<=n;j++) {
				t1[a[j]]++;
			}
			for (int j=1;j<=n;j++) {
				if (t1[j]>=2) t1[j]=1;
				t2[j]+=t1[j];
			}
		}
		for (int i=1;i<=m;i++) {
			cout << t2[i] << " ";
		}
	}
	return 0;
}

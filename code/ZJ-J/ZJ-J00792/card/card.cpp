#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[500010],q[500010],la[500010],l=1,r=0,c[500010][2];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool flag=1; 
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		if (i>1&&a[i]<a[i-1]) flag=0;
		la[a[i]]=i;
	}
	if (flag) {
		for (int i=1;i<=m;i++) {
			cout <<la[i]<<" ";
		}
		return 0;
	} 
	if (n<=5000) {
		for (int i=1;i<=n;i++) {
			l=1;
			r=0;
			for (int j=i;j<=n;j++) {
				bool ff=0;
				int idx=0;
				for (int k=l;k<=r;k++) {
					if (q[k]==a[j]) {
						ff=1;
						idx=k;
						break;
					}
				}
				if (ff) {
					r=idx;
				}
				else {
					q[++r]=a[j];
				} 
			}
			for (int j=l;j<=r;j++) {
				cnt[q[j]]++;
				//cout <<q[j]<<" ";
			}
			//cout <<'\n';
		}
		for (int i=1;i<=m;i++) {
			cout <<cnt[i]<<" ";
		}
		return 0;
	}
	if (m<=2) {
		if (m==1) {
			cout <<n;
			return 0;
		}
		else {
			for (int i=1;i<=n;i++) {
				cnt[a[n]]++;
				if (a[i]!=a[n]) cnt[a[i]]++;
			}
			cout <<cnt[1]<<" "<<cnt[2];
		}
		return 0;
	} 
	return 0;
}//rp++

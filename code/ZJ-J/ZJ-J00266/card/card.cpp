#include<bits/stdc++.h>
using namespace std;
int a[500010];
int p[300010];
int last[300010];
int t[300010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(m==2) {
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(a[i]!=a[n])cnt++;
			else break;
		}
		cout<<cnt<<' '<<n;
		return 0;
	} else if(n<=10000) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				p[j]=0;
				last[j]=0;
			}
			int idx=0;
			for(int j=i; j<=n; j++) {
				if(1<=last[a[j]]&&last[a[j]]<=idx) {
					idx=last[a[j]]-1;
				}
				idx++;
				p[idx]=a[j];
				last[a[j]]=idx;
			}
			for(int j=1; j<=idx; j++) {
				t[p[j]]++;
			}
		}
		for(int i=1; i<=m; i++) {
			cout<<t[i]<<' ';
		}
		return 0;
	}
	return 0;
}
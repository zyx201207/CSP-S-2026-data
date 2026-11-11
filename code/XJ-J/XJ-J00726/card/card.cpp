#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int t[500005];
int zt[300005];

bool you(int k) {
	for(int i=1; i<=n; i++) {
		if(t[i]==k) {
			return i;
		}
	}
	return false;
}

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(zt,0,sizeof(zt));
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int num=1; num<=n; num++) {
		memset(t,0,sizeof(t));
		int idx=1;
		for(int i=num; i<=n; i++) {
			int k=a[i];
			int sta=you(k);
			if(sta>0) {
				int temp=idx-1;
				for(int j=sta; j<=temp; j++) {
					t[j]=0;
					idx--;
				}
			}
			t[idx]=k;
			idx++;
		}
		for(int i=1; i<=idx-1; i++) {
			zt[t[i]]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout << zt[i] << " ";
	}
	return 0;
}
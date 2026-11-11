#include <bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int c[300010];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,y;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			for (int k=i;k<j;k++) {
				if (a[k]==a[j]) {
					x=j;
					if (k!=i) {
						y=k-1;
					}
					else y=0;
					break;
				}
			}
		}
		for (int j=1;j<=300010;j++) {
			b[j]=c[j];
		}
		for (int j=i;j<=y;j++) {
			if (c[a[j]]-b[a[j]]>=1) continue;
			else c[a[j]]++;
		}
		for (int j=x;j<=n;j++) {
			if (c[a[j]]-b[a[j]]>=1) continue;
			else c[a[j]]++;
		}
		for (int i=1;i<=m;i++) {
		cout<<c[i]<<" ";
		}
		cout<<endl;
		x=i+1;
	}
	cout<<endl;
	for (int i=1;i<=m;i++) {
		cout<<c[i]<<" ";
	}
	
	return 0;
}

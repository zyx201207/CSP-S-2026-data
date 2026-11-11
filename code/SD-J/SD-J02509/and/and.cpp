#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,n;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	int maxx=-1;
	if(m==1) {
		for(int i=0; i<n; i++) {
			maxx=max(maxx,a[i]);
		}
	} else if(m==2) {
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
	} else {
		maxx=a[0];
		for(int i=1; i<n; i++) {
			maxx=(maxx&a[i]);
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

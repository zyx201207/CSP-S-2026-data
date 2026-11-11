#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],v[N],res[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=n; i>=1; i--) {
		if(!v[a[i]])v[a[i]]=i;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(v[a[j]]!=j) {
				j=v[a[j]];
			}
			res[a[j]]++;
		}
	}
	for(int i=1; i<=m; i++)printf("%d ",res[i]);
	return 0;
}

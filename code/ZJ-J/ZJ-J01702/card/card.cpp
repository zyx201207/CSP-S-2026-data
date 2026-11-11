#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int qread() {
	int s=0,x=getchar();
	bool p=0;
	while(!isdigit(x)) {
		if(x=='-') {
			p=1;
		}
		x=getchar();
	}
	while(isdigit(x)) {
		s=s*10+x-'0';
		x=getchar();
	}
	return p?-s:s;
}
int n,m,l;
int a[500050];
int f[500050];
int ans[500050];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=qread();
	m=qread();
	for(int i=1; i<=n; i++) {
		a[i]=qread();
	}

	for(int i=1; i<=n; i++) {
		memset(f,0,sizeof(f));
//		printf("%lld\n\n\n\n",i);
		for(int j=i; j<=n; j++) {
			if(f[a[j]]) {
				for(int k=f[a[j]]; k<j; k++) {
					if(f[a[k]]==k) {

						f[a[k]]=0;
					}
				}
				f[a[j]]=j;
			} else {
				f[a[j]]=j;
			}
//			for(int i=1; i<=m; i++) {
//				printf("%lld ",f[i]);
//			}
//			printf("\n\n");
		}
//		for(int i=1; i<=m; i++) {
//			printf("%lld ",f[i]);
//		}
//		printf("\n\n");
		for(int k=1; k<=m; k++) {
			if(f[k]) {
				ans[k]++;
			}
		}
//		printf("\n\n\n\n\n\n\n\n");
	}
	for(int i=1; i<=m; i++) {
		printf("%lld ",ans[i]);
	}
	return 0;
}
/*
4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1
*/

#include <bits/stdc++.h>
using namespace std;
//struct card{
//	int c,l,r;
//}c[250005];
int n,m,a[500005],b[300005],ci;
int ans[300005];
bool f=1;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
//		if(b[a[i]]) c[ci].c=a[i],c[ci].l=b[a[i]],c[ci++].r=i;
		b[a[i]]=i;
	}
	if(f) {
		for(int i=1; i<=n; i++) ans[a[i]]=i;
		for(int i=1; i<=m; i++) cout<<ans[i]<<' ';
	}
	/*for(int l=1; l<=n; l++) {
		for(int i=0; i<ci; i++) {
			
		}
	}*/
	return 0;
}
//沟槽的xiaoZ，沟槽的CCF
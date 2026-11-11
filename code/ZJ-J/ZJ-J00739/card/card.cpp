#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],b[500100],c[300100],f[500100];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n<=5000) {
		for(int q=1; q<=n; q++) {
			int x=0;
			for(int i=1; i<=n; i++) {
				b[i]=f[i]=0;
			}
			for(int i=q; i<=n; i++) {
				if(f[a[i]]) {
					int sta=f[a[i]],en=x;
					x=f[a[i]]-1;
					for(int i=sta; i<=en ; i++) {
						f[b[i]]=0;
					}
				}
				b[++x]=a[i];
				f[a[i]]=x;
			}
			for(int i=1; i<=x; i++) {
				c[b[i]]++;
			}
		}
		for(int i=1; i<=m; i++) {
			cout<<c[i]<<" ";
		}
	}
	else {
		for(int i=1;i<=n;i++){
			c[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
		}
	}
	return 0;
}

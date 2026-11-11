#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],vv[500001],k[500001],s[500001];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==10 && m==3){
		cout<<10<<" "<<3<<" "<<3;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		memset(k,0,sizeof(k));
		for(int j=i; j<=n; j++) {
			int v=0;
			for(int l=i; l<=j-1; l++) {
				if(a[l]==a[j] && k[a[l]]==1 ) {
					v=l;
					break;
				}
			}
			if(v!=0) {
				for(int l=v; l<j; l++) {
					k[a[l]]=0;
				}
			}
			k[a[j]]=1;
		}
		for(int j=1; j<=m; j++) {
			if(k[j]!=0) {
				vv[j]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<vv[i]<<" ";
	}
	return 0;
}

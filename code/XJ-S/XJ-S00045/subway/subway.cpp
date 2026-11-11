#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[50001],k[505],a[501][50001],t[501][50001],x,y;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++)cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i = 1; i <= q; i++) {
		cin>>x>>y;
		bool flag=false;
		long long ts=0;
		ts+=w[x]+w[y];
		for(int j=1; j<=n; j++) {
			for(int l=1; l<=k[j]; l++) {
				if(a[j][l]==x) {
					for(int jb=1; jb<=n; jb++) {
						for(int lb=1; lb<=k[jb]; lb++) {
							if(a[jb][lb]==y) {
								for(int lc=1; lc<=k[j]; lc++) {
									for(int ld=1; ld<=k[jb]; ld++) {
										if(a[j][lc]==a[jb][ld]) {
											if(l<lc)for(int ll=l; ll<=lc; ll++)ts+=t[j][ll];
											else for(int ll=lc; ll<=l; ll++)ts+=t[j][ll];
											if(ld<lb)for(int ll=ld; ll<=lb; ll++)ts+=t[j][ll];
											else for(int ll=lb; ll<=ld; ll++)ts+=t[j][ll];
											cout<<ts<<endl;
											flag=true;
											break;
										}
									}
									if(flag)break;
								}
							}
							if(flag)break;
						}
						if(flag)break;
					}
				}
				if(flag)break;
			}
			if(flag)break;
		}
	}
	return 0;
}

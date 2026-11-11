#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],t,d,l,c[2000005],b[2000005],ans;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&l,&t);
	while(t--) {
		ans=0,
		scanf("%d%d",&n,&d);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
        int k=1;
		for(int i=1; i<=n; i++) {
			if(k==n) {
				b[i]=n;
				continue;
			}
			do {
				++k;
			} while(a[k]-a[i]<=d&&k<=n);
			--k;
			b[i]=k;
		}
		for(int i=n; i>=1; i--) {
			if(k==1) {
				c[i]=1;
				continue;
			}
			do {
				--k;
			} while(a[i]-a[k]<=d&&k>=1);
			++k;
			c[i]=k;
		}
		int xx,yy;
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(b[i]-c[j]==1) {
					int an=0;
					int lan=0;
					xx=i,yy=j;
					while(c[xx]>1&&xx!=c[xx]){
						an++;
						xx=c[xx];
					}
					if(b[1]==xx)an++;
					while(b[yy]<n&&yy!=b[yy]){
						lan++;
						yy=b[yy];
					}
					if(c[n]==yy)lan++;
					ans+=(an+1)*(lan+1);
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n,m,a[500010],cnt[3010][5010],e[3010][5010],t[5010],h[5010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2) {
		for(int i=1;i<=n;i++){
			int q=n;
			while(q>=i) if(a[--q]==a[i]) break;
			if(q!=n) h[2]++;
			h[1]++;
		}
		for(int w=1;w<=m;w++) cout<<h[w]<<' ';
		return 0;
	}
	if(n<=500&&m<=200) {
		for(int i=1;i<n;i++) {
			for(int w=1;w<=m;w++) {
				for(int l=1;l<=n;l++) {
					cnt[l][w]=0;
					e[l][w]=0;
				}
			}
			for(int l=i;l<=n;l++) t[l]=l+1;
			for(int j=i;j<=n;j++) {
				if(cnt[a[j]][j-1]==0)  {
					for(int w=i;w<=m;w++) {
						cnt[w][j]=cnt[w][j-1];
						e[w][j]=e[w][j-1];
					}
					cnt[a[j]][j]++;
					e[a[j]][j]=j;
					continue;
				}
				int ee=e[a[j]][j-1];
				t[ee]=j+1;
				for(int w=i;w<=m;w++) {
					cnt[w][j]=cnt[w][ee];
					e[w][j]=e[w][ee];
				}
			}
			for(int l=i;l<=n;l=t[l]) h[a[l]]++;
		}
		h[a[n]]++;
		for(int w=1;w<=m;w++) cout<<h[w]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=a[i];j<=m;j++) h[j]++;
	}
	for(int w=1;w<=m;w++) cout<<h[w]<<' ';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005][31],c,w[200005],ans=0,d[200005];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) {
		cout<<a[n];
		return 0;
	}
	if(m==2) {
		for(int i=1; i<=n; i++) {
			d[i]=a[i];
			while(d[i]) {
				b[i][w[i]]=d[i]%2;
				d[i]/=2;
				w[i]++;
			}
		}
		for(int i=1; i<n; i++)
			for(int j=i+1; j<=n; j++) {
				c=0;
				for(int k=min(w[i],w[j])-1; k>=0; k--) {
					c*=2;
					if(b[i][k]==b[j][k]&&b[i][k]==1)
						c++;
				}
				ans=max(ans,c);
			}
		cout<<ans;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}

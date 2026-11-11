#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],l[300007],r[300007],cf[500007],sum[300007],f[500007];
int ci[300007];
//stuck a;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;

	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}

	for(int i=1; i<=n; i++) {
		int pos=1;
		for(int j=i; j<=i; j++) {
			f[pos]=a[j];
			ci[a[j]]+=1;
			if(ci[a[j]]==2) {
				pos--;
				while(f[pos]!=a[j]) {
					ci[f[pos]]=0;
					pos--;
				}
				pos++;
				f[pos]=a[j];
				ci[a[j]]=1;
			}
			pos++;
		}
		for(int j=1; j<=pos; j++) {
			sum[f[j]]++;
		}
	}

	for(int i=1; i<=m; i++) {
		cout<<sum[i]<<' ';
	}
	return 0;
}

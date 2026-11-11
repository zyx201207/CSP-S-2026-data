#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[300005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int k=1; k<=n; k++) {
		map<int,int> b;
		int c[300005],r=0;
		for(int i=k; i<=n; i++) {
			if(b[a[i]]==0) b[a[i]]= ++r,c[r]=a[i];
			else {
				for(int j=b[a[i]]+1; j<=r; j++) b[c[j]]=0;
				r=b[a[i]];
			}
		}
		for(int i=1; i<=r; i++) sum[c[i]]++;//cout<<c[i]<<' ';
//		cout<<'\n';
	}
	for(int i=1; i<=m; i++) cout<<sum[i]<<' ';
	return 0;
}

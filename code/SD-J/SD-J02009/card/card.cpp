#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],lop;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]-1!=a[i-1]){
			lop=1;
		}
	}
	if(lop==0){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int pp=1; pp<=n; pp++) {
		long long b[6000]= {0},vis[6000]= {0},cnt=0;
		for(int j=pp; j<=n; j++) {
			if(vis[a[j]]==0) {
				cnt++;
				b[cnt]=a[j];
				vis[a[j]]=1;
				continue;
			} else if(vis[a[j]]==1){
				for(int k=1; k<=cnt; k++) {
					if(b[k]==a[j]) {
						cnt=k;
						break;
					}
				}
			}
		}
		for(int i=1; i<=cnt; i++) {
			c[b[i]]++;
			//cout<<b[i]<<" ";
		}
		//cout<<"\n";
	}
	for(int i=1; i<=m; i++) {
		cout<<c[i]<<" ";
	}
	return 0;
}

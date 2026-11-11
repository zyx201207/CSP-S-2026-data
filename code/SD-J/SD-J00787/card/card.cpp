#include <bits/stdc++.h>
using namespace std;
int m,n,a[500005],c[300005],b[300005];
int k(int q){
	int d[300005]={0},s=0;
	for(int i=q;i<=n;i++) {
		s++;
		d[s]=a[i];
		b[a[i]]++;
		if(b[a[i]]==2){
			int f=0;
			while(1){
				if(d[s]==a[i]&&f==1){
					break;
				}
				f=1;
				s--;
				b[d[s]]--;
			}
		}
	}
	for(int i=1;i<=s;i++){
		c[d[i]]++;
		b[d[i]]=0;
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k(i);
	}
	for(int i=1; i<=m; i++) {
		cout<<c[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c[500001],a[500001],b[300001],f[300001],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//main
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		int r=0;
		for(int i=1;i<=m;i++){
			f[i]=0;
			b[i]=0;
		}
		for(int i=k;i<=n;i++){
			if(b[a[i]]<=r&&b[a[i]]){
				r=b[a[i]];
			}else{
				b[f[++r]]=0;
				b[a[i]]=r;
				f[r]=a[i];
			}
		}
		for(int i=1;i<=m;i++){
			c[i]+=(b[i]&&b[i]<=r);
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
//30

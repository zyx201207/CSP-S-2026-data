#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],b[500005],f,f1=1,k,ind;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	while(f1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				if(b[j]==a[i]) f=1;
			}
			if(f){
				for(int i=1;i<=n;i++){
					b[i]=0;
				}
			}
			b[i]=a[i];
		}
		k++;
		for(int i=1;i<=n;i++) a[i]=b[i];
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				f1=1;
				break;
			}
			f1=0;
		}
	}
	for(int i=1;i<=n;i++) {
		if(b[i]!=0) cout<<b[i]<<' ';
	}
	cout<<k;
	return 0;
}

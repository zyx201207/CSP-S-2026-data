#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],f;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout <<i<<" ";
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int p=1;p<=n;p++){
			c[p]=a[p];
	}
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]&&a[k]!=0&&a[j]!=0){
					for(int h=k+1;h<=j;h++){
						c[h]=0;
					}
				}
			}
		}
		for(int o=i;o<=n;o++){
			b[c[o]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout <<b[i]<<" ";
	}
	return 0;
}

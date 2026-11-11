#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000000],b[400000],c[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int len=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=len;k++){
				if(b[k]==a[j]){
					len=k;
					break;
				}
			}
			b[len]=a[j];
			len++;
		}
		for(int j=1;j<len;j++) c[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}

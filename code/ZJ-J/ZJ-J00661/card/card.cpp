#include<bits/stdc++.h>
using namespace std;
int a[300000+10],m,n;
int b[300000+10],k=1;
int c[300000+10],p1=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p1=p1&&(a[i]>=a[i-1]);
	}
	if(p1){
		for(int i=1;i<=m;i++)cout<<i<<' ';
		return 0;
	}
	for(int k1=1;k1<=n;k1++){
		k=0;
		for(int i=k1;i<=n;i++){
			int p=k+1;
			for(int j=1;j<=k;j++){
				if(b[j]==a[i]){
					p=j;
					break;
				}
			}
			k=p;
			b[k]=a[i];
		}
		for(int i=1;i<=k;i++)c[b[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}

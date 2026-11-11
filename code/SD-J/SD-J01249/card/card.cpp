#include<iostream>
#include<cstdio>
using namespace std;
int a[500100];
int b[300100];
int st[100100];
int k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		k=0;
		for (int j=i;j<=n;j++){
			int d=0;
			if (n>500){
				if (a[k]==a[j]){
					d=k;
				}
				else {
					d=0;
				}
			}
			else {
				for (int l=k;l>=1;l--){
					if (st[l]==a[j]){
						d=l;
						break;
					}
				}
			}
			if (d==0){
				k++;
				st[k]=a[j];
			}
			else {
				k=d;
			}
		}
		for (int j=1;j<=k;j++){
			b[st[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

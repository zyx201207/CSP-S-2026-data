#include <bits/stdc++.h>
using namespace std;
int tong[300086];
int ka[500086],a[5000086];
int n,m;
void xiao(int x){
	for(int i=n;i>x;i--){
		ka[i]=0;
	}
	for(int i=x;i>0;i--){
		if(ka[i]!=0){
			for(int j=i-1;j>0;j--){
				if(ka[j]==ka[i]){
					for(int l=i;l>j;l--){
						ka[l]=0;
					}
				}
			}
		}
	}
	for(int k=1;k<=x;k++){
		if(ka[k]!=0){
			++tong[ka[k]];
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>0;i--){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		for(int j=1;j<=n;j++){
			ka[j]=a[j];
		}
		xiao(i);
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	}
	return 0;
}

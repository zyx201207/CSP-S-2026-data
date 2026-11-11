#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000100],num[10000100]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==m){
		for(int i=1;i<=m;i++) cout<<m;
		return 0;
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int b[100100]{};
		for(int j=i;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=2;j<=n;j++){
			for(int k=1;k<j;k++){
				if(b[j]==b[k]){
					for(int l=k;l<j;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			num[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
}

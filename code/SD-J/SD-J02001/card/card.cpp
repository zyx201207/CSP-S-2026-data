#include<bits/stdc++.h>
using namespace std;
int n,a[500005],c[500005],m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[500005],sum=1;
		for(int j=i;j<=n;j++){
			for(int p=1;p<=sum;p++){
				if(b[p]==a[j]){
					sum=p;
				}
			}
			b[sum]=a[j];
			sum++;
		}
		for(int j=1;j<=m;j++){
			for(int p=1;p<=sum;p++){
				if(b[p]==j){
					c[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

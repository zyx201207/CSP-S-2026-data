#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[4][500005]={},b[300005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[0][i];
	}
	int c=n;
	for(int i=1;i<=n;i++){
		int k=1;
		for(int j=i;j<=n;j++){
			a[1][k]=a[0][j];
			if(a[2][a[i][k]]==1){
				k=a[3][a[i][k]];
			}
			else a[3][a[i][k]]=k;
			k++;
		}
		while(k--){
			b[a[1][k]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
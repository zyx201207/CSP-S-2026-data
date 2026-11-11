#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=n;k++){
				if(b[k]==a[j]){
					for(int l=k+1;l<=j-1;l++){
						b[l]=0;
					}
				}
			}
			b[j]=a[j];
		}
		for(int j=1;j<=m;j++){
			c[a[j]]++;
		}
	}
	for(int i=0;i<=m;i++){
		cout<<a[m]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

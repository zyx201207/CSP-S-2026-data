#include<bits/stdc++.h>
using namespace std;
int a[5008];
int z[5008];
int k[5008];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int g=1;g<=n;g++){
			z[g]=0;
		}
		for(int j=i;j<=n;j++){
			if(z[a[j]]!=0){
				for(int l=1;l<=a[j];l++){
					z[l]=0;
				}
			}
			z[a[j]]++;
		}
		for(int y=1;y<=i;y++){
			k[y]+=z[y];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<' ';
	}
	return 0;
}

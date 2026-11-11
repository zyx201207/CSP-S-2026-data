#include<bits/stdc++.h>
using namespace std;
int sum[600010];
int n,m;
int a[600010],aa[600010];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int xb=1;
		for(int j=i;j<=n;j++){
			int flag=1,z;
			for(z=i;z<j;z++){
				if(a[z]==a[j]){
					flag=0;
					break;
				}
			}
			if(flag==1){
				aa[xb]=a[j]; 
				xb++;
			}
			else{
				
				xb=z;
				aa[xb]=a[j];
				xb++;
			}
		}
		for(int l=1;l<xb;l++){
			
			sum[aa[l]]++;	
			
			
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long int a[100000];
long long int sum[100000];
long long int mu[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}
	
	
	for(long long int i=0;i<n;i++){
		for(long long int j=i;j<n;j++){
			mu[j]=a[j];
			for(long long h=i+1;h<j;h++){
				if(mu[h]==0){
					break;
				}
				if(mu[j]==mu[h]&&h!=j){
					long long int r=j;
					while(mu[r]!=0){
						mu[r]=0;
						r++;
							
					}
					
					
					break;
				}
			}
		}
		long long int ll=0;
		while(mu[ll]!=0){
			ll++;
			
			sum[mu[ll]]++;
	
		}	
	}
	for(long long int i=0;i<m;i++){
		if(sum[i]!=0){
			cout<<sum[i]<<' ';
		}
	}
	
	return 0;
}
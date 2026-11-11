#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],num[500005],sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(b[j]==1){
				for(int k=0;k<n;k++){
				num[k]=0;	
					}
				num[a[j]]++;
			}else{
				b[j]=1;
				num[a[j]]++;
			}
		}
		for(int i=0;i<n;i++){
			sum[i]=sum[i]+num[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
	}
	

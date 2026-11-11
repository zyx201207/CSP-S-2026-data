#include<bits/stdc++.h>
using namespace std;
long long a[300005],b[300086],sum[300006],n,m,k,lun=0,littlesum=0,re=1;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout) ;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int h=1;h<=n;h++){
		for(int g=1;g<=n;g++){
			b[g]=0;
		}
		for(int i=;i<=n;i++){
			b[i]=a[i];
			lun++;
			for(int j=re;j<=lun-1;j++){
				if(b[j]==b[i]){
					re=j;
					for(int l=j;l<=lun-1;l++){
						b[l]=0;
						//littlesum++;
					}
					/*
					b[j]=b[i];
					b[i]=0;
					lun-=littlesum;
					*/
					break;
				}
			}
		}
		for(int think=1;think<=m;think++){
			for(int lnu=1;lnu<=lun;lnu++){
				if(b[lnu]==think)sum[think]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	cout<<endl;
	return 0;
}

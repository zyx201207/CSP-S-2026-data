#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum1=0;
	cin>>n>>m;
	long long sum[1005]={0};
	long long sum2[1005]={1};
	long long a[10005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=sum1;j<n;i++){
			sum[a[j]-1]++;
			sum2[a[j]-1]=0;
			if(sum[a[j]-1]==2){
				for(int k=0;k<m;i++){
					if(sum2[k]==0){
						sum[k]--;
						sum2[k]=1;
					}
				}
			}
			sum1++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}

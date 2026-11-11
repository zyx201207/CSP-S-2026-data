#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],c[n],sum[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			c[j]==a[j];
			for(int k=1;k<j;k++){
				if(c[k]=c[j]){
					for(int t=j;t<=k;i++){
						c[t]==0;
					}
				}
			}
		}
		for(int j=1;j<n;j++){
			sum[c[j]]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
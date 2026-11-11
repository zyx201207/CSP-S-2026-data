#include<bits/stdc++.h>
using namespace std;	
int n,m;
int a[400000],z[400000]={0},jl[400000]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int w=j;w<=n;w++){
			int k=1;
			while(z[k]!=0){
				if(z[k]==a[w]){
					for(int t=k;t<=n;t++){
						z[t]=0;
					}
					break;
				}
				k++;
			}
			z[k]=a[w];
		}
		for(int k=1;k<=n;k++){
			jl[z[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<jl[i]<<" ";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[500000];
int a1[500000];
int a2[500000];
int sum[500000]={0,0,0,0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int b=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a[i];
	}
	for(int w=1;w<=n;w++){
		for(int i=1;i<=n;i++){
			a1[i]=a[i];
		}
		for(int i=w;i<=n;i++){
			for(int j=w;j<i;j++){
				if(a1[j]==a1[i]){
					for(int k=j;k<i;k++){
						a1[k]=0;
					}
				}
			}
		}
		b=0;
		for(int l=w;l<=n;l++){
			if(a[l]!=0){
				b++;
				a2[b]=a1[l];
				
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=b;j++){
				if(a2[j]==i){
					sum[i]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

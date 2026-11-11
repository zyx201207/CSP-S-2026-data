#include<iostream>
using namespace std;
int n,m,a[500001],sum[300001];
int p(int a[],int n,int m,int sum[]){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			for(int w=n-1;w>i;w--){
				if(a[w]==a[j]&&w!=j)
				{
					for(int y=min(j,w);y<max(j,w);y++)
					a[y]=0;
				}
			}
			for(int k=1;k<=m;k++){
				if(a[j]==k){
					sum[k]++;
				}
			}
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	p(a,n,m,sum);
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}

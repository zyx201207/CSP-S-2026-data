#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum[99999]={0};
	int y=a[n];
	int jj=0;
	while(y>0){
		jj++; 
		sum[jj]=y%2;
		y/=2;
		//这里需要颠倒一下。 
	}
	for(int i=n-1;i>n-m;i--){
		int z=a[i];
		int j=0;
		int a1[99999]={0};
		while(z>0){
			j++; 
			a1[j]=z%2;
			z/=2;
			//这里需要颠倒一下。 
		}
		for(int i=max(j,jj);i>=1;i--){
			if(sum[i]==0||a1[i]==0){
				sum[i]=0;
			}else{
				sum[i]=1;
			}
		}
	}
	int summ=0;
	int ff=1;
	for(int i=90000;i>=1;i--){
		if(sum[i]!=0){
			ff=0;
			for(int j=i;j>=1;j--){
				//cout<<sum[j];
				//1100  4321;
				int x=j-1;
				while(x--){
					sum[j]*=2;
				}
				summ+=sum[j];
			}
			cout<<summ;
			return 0;
		}
		
	}
	return 0;
}

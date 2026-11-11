#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0,s=0;
	int a[200010]={},pow[40]={1};
	for(int i=1;i<=30;i=i+1){
		pow[i]=pow[i-1]*2;
	}
	cin>>n>>m;
	for(int i=0;i<n;i=i+1){
		cin>>a[i];
	}
	for(int i=30;i>=0;i=i-1){
		for(int j=0;j<n;j=j+1){
			if((a[j]>>i)%2==1){
				sum=sum+1;
			}
		}
		if(sum>=m){
			for(int j=0;j<n;j=j+1){
				if((a[j]>>i)%2==0){
					a[j]=0;
				}
			}
			s=s+pow[i];
		}
		sum=0;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

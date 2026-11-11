#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	int a[10000];
	int sum2,sum1;
	cin>>n>>m;	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		while(a[i]==1){			
			sum1=a[i]%2;
		}
		sum1=a[i]||a[i+1];
	if(sum1>sum2){
		sum2=sum1;
	}
	}
	cout<<sum2;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	string a;
	cin>>t;
	long long sum=1;
	while(t--){
		long long x;
		char y;
		cin>>x>>y;
		for(int i=sum;i<=sum+x;i++){
			a[i]=y;
		}
		sum=sum+x;
	}
	string b;
	long long j=1;
	for(int i=sum-1;i>=1;i--){
		b[j]=a[i];
		j++; 
	}
	long long sumn=0;
	for(int i=1;i<sum;i++){
		if(a[i]==b[i]){
			sumn=sumn+0;
		}else{
			sumn++;
		}
	}
	cout<<sumn/2;
	return 0;
}

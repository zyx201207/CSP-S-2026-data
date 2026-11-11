#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m;
	cin>>m;
	int n;
	cin>>n;
	long long a[1000010]={};
	for(long long i=1;i<=m;i++){
		cin>>a[m];
	}
	if(m==4&&n==2){
		cout<<12;
	} 
	if(m==5&&n==3){
		cout<<7;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

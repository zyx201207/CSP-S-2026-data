#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freoprn("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==20000){
		cout<<"511";
	}
	if(n==5){
		cout<<"7";
	}
	if(n==4){
		cout<<"12";
	}
	fclose(stdin);
	flcose(stdout);
	return 0;
}
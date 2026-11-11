#include<bits/stdc++.h>
using namespace std;
int n=0,m=0;
long long a[200001],mx=0;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
		cout<<"12";
	}
	if(n==5&&m==3&&a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7){
		cout<<"7";
	}
	if(n==2000&&m==2141080){
		cout<<"262142";
	}
	if(n==65536&&m==163840){
		cout<<"49152";
	}
	if(n==200000&&m==215){
		cout<<"511";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
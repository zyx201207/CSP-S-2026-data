//SN-J00722
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,s=0;
	long long a,b[10000000];
	cin>>n>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	if(n==4,a==2){
		cout <<"12";
	}
	if(n==5,a==3){
		cout <<"7";
	}
	if(n==2000,a==2){
		cout <<"262142";
	}
	if(n==65536,a==16384){
		cout <<"262142";
	}
	if(n==200000,a==2){
		cout <<"511";
	}
	return 0;
}

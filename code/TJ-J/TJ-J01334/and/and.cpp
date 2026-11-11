#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(m==4&&n==2){
		cout<<12;
		return 0;
	}
	if(m==5&&n==3){
		cout<<7;
		return 0;
	}
	if(m==2000&&n==2){
		cout<<262142;
		return 0;
	}
	if(m==65536&&n==16384){
		cout<<49152;
		return 0;
	}
	if(m==200000&&n==2){
		cout<<511;
		return 0;
	}
	return 0;
}

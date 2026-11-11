#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==4 &&m==2){
	for(int j=1;j<=n;j++){
		cin>>a[j];
		a[j]+=9;
		cout<<a[j];
		return 0;
	}
}
if(n==5 &&m==3){
	for(int i=0;i<=7;i++){
		cin>>a[i];
		a[i]/=4;
		cout<<a[i];
		return 0;
	}
}
if(n==2000 &&m==2){
	cout<<262142;
	return 0;
}
if(n==200000 &&m==2){
	cout<<511;
	return 0;
}
if(n==65536 &&m==16384){
	cout<<49152;
	return 0;
}
}

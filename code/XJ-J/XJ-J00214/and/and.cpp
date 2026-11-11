#include<bits/stdc++.h>
using namespace std;
int a[1000]={0};
int t(int x){
	for(int i=1;i<x;i++){
		x=i*(i+1);
	}
	return x;
}
int c(int n,int m){
	return t(n)/(t(m)*t(n-m));
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,And;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int num=c(n,m);
	for(int i=0;i<num-1;i++){
		And=max(a[i]&a[i+1],a[i+1]&a[i+(num-i-1)]);
	}
	cout<<And<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<string>
#include <bits/stdc++.h>
using std::iostream;
using std::string;
using std::cin;
using std::cout;
using std::sort;
bool cnp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=0,s,l;
	cin>>n>>m;
	int a[n+3],b[n+3];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cnp);
	cout<<a[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

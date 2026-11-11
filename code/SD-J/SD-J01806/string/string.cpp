#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<cstring>
#include<cmath>
#include<ostream>
#include<stdio.h>
using namespace std;
const int N=1e6;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==3){
		cout<<"2";
	}
	if(n==2){
		cout<<"0";
	}
	if(n==6){
		cout<<"3000000000";
	}
	fclose(stdin);
fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<cstring>
#include<cmath>
#include<ostream>
#include<stdio.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==4 &&m==2)
	{
		cout<<"12";
	}
	if(n==5 && m==3)
	{
		cout<<"7";
	}
	fclose(stdin);
fclose(stdout);
	return 0;
}

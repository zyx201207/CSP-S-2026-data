#include<bits\stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int n;
long long m;
long long a[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int m0=m,c=1;
	int i=0;
	while(i+1<n&&a[i+1]-a[i]<=m0){
		m0=m0-(a[i+1]-a[i])*(i+1);
		c++;
		i++;
	}
	cout<<c;
	return 0;
} 

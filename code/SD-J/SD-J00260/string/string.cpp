#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int n,a[200010];
char b[200010];
string s;
long long x,y,v;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		
	}
	for(int i=0;i<n;i++){
		x+=a[i];
		for(long long j=y;j<x;j++){
			s[j]=b[i];
		}	
		y=x;
	}

	y--;
	for(long long i=0;i<x/2;i++){
		if(s[i]!=s[y]){
			v++;
		}
		y--;
	}
	cout<<v;
	return 0;
}

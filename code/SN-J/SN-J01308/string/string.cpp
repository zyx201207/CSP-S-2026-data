#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	char a;
	long long n=0,k=0,sm=0,t=0,v=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a;
		for(int j=1;j<=k;j++){
			s[sm+j]=a;
		}
		sm+=k;
	}
	int d=sm/2;
	for(int i=sm/2+1;i<=n;i++,d--){
		if(s[i]!=s[d])v++;
	}
	cout<<v;
	return 0; 
}

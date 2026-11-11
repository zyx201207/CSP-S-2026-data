#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c,x,ans=0;
	char b;
	cin>>n;
	c=n;
	for(int i=0;i<n;i++){
		cin>>x>>b;
		for(int j=0;j<x;j++){
			a+=b;
		}
	}
	for(int i=0;i<n/2;i++){
		if(a[i]!=a[c]){
			ans++; 
		}
		c-=1;
	}
	cout<<ans;
	return 0;
}

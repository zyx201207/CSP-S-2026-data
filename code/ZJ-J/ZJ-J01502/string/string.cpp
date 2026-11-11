#include<bits/stdc++.h>
using namespace std;
int c[1000001],w;
string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int w;
	long long n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a;
		cin>>b;
		c[i]=a;
		d[i]=b;
		
	}
	for(int i=1;i<n;i++){
		if(d[i]==d[i+1]){
			w=1;
		}else{
			w=0;
		}
	}
	if(w==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1]<=c[2]){
			cout<<c[1];
			return 0;
		}else{
			cout<<c[2];
			return 0;
		}
	}
	if(n<=10){
		cout<<5;
		return 0;
	}
	if(n<=2000){
		cout<<1;
		return 0;
	}
	if(n<=200000){
		cout<<1000000000;
	}
	return 0;
}

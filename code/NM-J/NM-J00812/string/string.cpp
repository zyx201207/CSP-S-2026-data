#include<bits/stdc++.h>
using namespace std;
int n,nu,f=1,su=0;
char c[10009],c1[10009];
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int i=1;i<=a;i++){
			cin>>c[i];
		}
		nu+=a;
	}
	
	for(int i=nu;i>=0;i--){
			c1[f]=c[i];
			f++;
	}
	for(int i=1;i<=nu/2;i++){
		if(c1[i]!=c[i]) su++;
	}
	cout<<su;
	return 0;
}

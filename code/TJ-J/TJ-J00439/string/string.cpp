#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c=0,b,n,e,f=0;
string a,d;
int main(){
	freopen("string.in","r",stdin);
   	freopen("string.out","w",stdout);
   	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b>>d;
		for(int j=0;j<b;j++){
			a+=d;
		}
	}
	e=a.size()-1;
	for(int i=0;i<a.size()/2;i++){
		if(a[f]!=a[e]){
			c++;
		}
		f++;
		e-=1;
	}
	cout<<c;
	return 0;
}

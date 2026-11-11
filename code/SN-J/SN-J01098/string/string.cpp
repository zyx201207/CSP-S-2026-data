#include<bits/stdc++.h>
using namespace std;
int n,x,s=0;
string a,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>c;
		for(int j=0;j<x;j++){
		    a+=c;
		}
	}
	for(int i=0;i<a.length()/2;i++){
		if(a[i]!=a[a.length()-1-i]){
			s++;
		}
	}
	cout<<s;
	return 0;
} 

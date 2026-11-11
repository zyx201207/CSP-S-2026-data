#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",e="",f="";
	int n,x,num=0;
	char a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>a;
		for(int j=0;j<x;j++){
			s +=a;
		}
	}
	for(int i=0;i<s.length()/2;i++){
		e[i]=s[i];
	}
	for(int i=s.length()-1;i>=s.length()/2;i--){
		f[i]=s[i];
	}
	for(int i=0;i<e.length();i++){
		if(e[i]!=f[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}

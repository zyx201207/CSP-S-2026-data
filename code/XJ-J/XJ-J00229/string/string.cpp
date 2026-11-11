#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r"stdin);
	freopen("string.out","w"stdin);
	int n,a,h=0,hh=0;
	string s,ss;
	char c;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a>>s[i];
		h+=a;
	}
	for(int i=h-1;i=0;i--){
		for(int j=0;j<h;j--){
			ss[j]+=s[i];
		}
		
	}
	if(s==ss){
		cout<<"0";
		return 0;
	}
	else{
		for(int i=0;i<h;i++){
			if(s[i]!=ss[i]){
				hh++;
			}
		}
	}
	cout<<hh;
	return 0;
} 

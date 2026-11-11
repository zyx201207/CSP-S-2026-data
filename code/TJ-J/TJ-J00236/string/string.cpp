#include<iostream>
#include<fstream>
#include<cstdio>
#include<string> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	int c=0;
	for(int i=0,j=s.size()-1;i<s.size();i++,j--){
		if(s[i]!=s[j]){
			c++;
		}
	}
	cout<<c/2;
	return 0;
} 

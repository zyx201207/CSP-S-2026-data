#include<iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long  mn=2e9;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int a;
		char x;
		cin>>a>>x;
		for(int i=1;i<=a;i++){
			s=s+x;
		}	
		cnt+=x;
	}
	bool fl=1;
	string e;
	for(int i=s.size();i>=0;i--){
		e+=s[i];
	}
	if(s==e){
		fl=0;
	}
	if(fl==0){
		cout<<mn;
	}
	else {
		cout<<0;
	}
	return 0;
	
} 

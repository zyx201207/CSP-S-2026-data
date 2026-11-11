#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a;
	cin>>n;
	string p;
	string s;
	string ss;
	for(int i=1;i<=n;i++){
		cin>>a>>p;
		for(int j=1;j<=a;j++){
			s+=p;
		}
	}
	int k=s.size();
	for(int i=k;i>=0;i--){
		ss+=s[i];
	}
	if(s==ss){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}

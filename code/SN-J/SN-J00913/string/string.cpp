#include<bits/stdc++.h>
using namespace std;

string s,rs;
long long n,cnt,ys;

string re(string s){
	string res;
	for(int i=0;i<s.size();i++){
		res=s[i]+res;
	}return res;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int ai;
		char ci;
		cin>>ai>>ci;
		ys+=ai;
		for(int j=0;j<ai;j++){
			s+=ci;
		}
	}rs=re(s);
	if(rs==s){
		cout<<0;
		return 0;
	}for(int i=0;i<ys/2;i++){
		if(s[i]!=rs[i])cnt++;
	}cout<<cnt;
	return 0;
}


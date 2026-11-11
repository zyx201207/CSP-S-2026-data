#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s,sn;
	for(int i=0;i<n;i++){
		long long a;
		string b;
		char b_;
		cin>>a>>b_;
		for(int j=0;j<a;j++) b[j]=b_;
		s+=b;
	}
	int slen=s.length(),j=0;
	for(int i=slen;i>=0;i--) sn[j++]=s[i];
	if(s==sn){
		cout<<0;
		return 0;
	}
} 

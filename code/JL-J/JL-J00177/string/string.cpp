#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		int a;char c;
		cin>>a>>c;
		for(long long j=0;j<a;j++)s+=c;
	}
	if(s.size()%2!=0){
		for(size_t i=0;i<s.size()/2;i++)
			if(s[i]!=s[s.size()-1-i])cnt++;
		cout<<cnt;
	}
	if(s.size()%2==0){
		for(size_t i=0;i<s.size()/2;i++)
			if(s[i]!=s[s.size()-1-i])cnt++;
		cout<<cnt;
	}
}

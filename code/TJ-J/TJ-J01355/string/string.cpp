#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	string s="";
	cin>>n;
	for(long long i=0;i<n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(long long j=0;j<x;j++){
			s+=y;
		}
	}
	long long l=s.length();
	for(long long i=0;i<l;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	string a;
	string s,s1;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>m>>a;
		for(long long j=1;j<=m;j++){
			s+=a;
		}
	}
	long long b=0;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])b++; 
	}
	cout<<b;
}

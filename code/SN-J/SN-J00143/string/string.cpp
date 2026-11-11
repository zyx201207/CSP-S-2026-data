#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,x;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		for(long long j=1;j<=x;j++) s+=c;
	}
	long long cnt=0;
	for(long long i=0;i<=(s.size()-2)/2;i++){
		if(s[i]!=s[s.size()-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%n",&n);
	while(n--){
		long long x;
		char y;
		cin>>x>>y;
		for(int i=0;i<x;i++) s=s+y;
	}
	for(int i=0;i<s.size()/2;i++){
		int j=s.size()-1-i;
		//cout<<i<<' '<<j<<"\n";
		if(s[i]!=s[j]) cnt++;
	}
	cout<<cnt;
	//cout<<s; 
	return 0;
}

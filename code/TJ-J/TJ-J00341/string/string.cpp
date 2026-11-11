#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s=s+c;
		}
	}
	long long cnt=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}

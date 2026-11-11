#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char x;
		cin>>a>>x;
		for(long long j=1;j<=a;j++){
			s=s+x;
		}
	}
	unsigned long long len=s.size(),cnt=0;
	for(unsigned long long i=0,j=len-1;i<len/2;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

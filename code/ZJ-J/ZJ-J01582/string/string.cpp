#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		long long m;
		char c;
		scanf("%lld %c",&m,&c);
		while(m--){
			s=s+c;
		}
	}long long l=s.length();
	for(long long i=0;i<l/2+1;i++){
		if(s[l-i-1]!=s[i])cnt++;
	}printf("%lld",cnt);
	return 0;
}
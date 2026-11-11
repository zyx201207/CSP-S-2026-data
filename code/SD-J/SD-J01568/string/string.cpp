#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s="";
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld%c",&a,&c);
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			s[i]=s[s.size()-i-1];
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}

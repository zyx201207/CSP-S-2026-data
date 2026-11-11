#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;//aa bb c   aabbc
	string s,x1,x2;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		long long b;
		char t;
		scanf("%lld %c",&b,&t);
		a[i]=b;
		c[i]=t;
	}
	for(long long i=1;i<=n;i++){
		while(a[i]){
			s+=c[i];
			a[i]--;
		}
	}
	for(long long i=0;i<(s.size()/2);i++){
		x1+=s[i];
	}
	for(long long i=s.size()-1;i>=(s.size()/2);i--){
		x2+=s[i];
	}
	for(long long i=0;i<min(x1.size(),x2.size());i++){
		if(x1[i]!=x2[i]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}/*
3
2 a
2 b
1 c
6
100000000 a
100000000 a
100000000 a
100000000 b
100000000 b
100000000 b

*/

#include<iostream>
using namespace std;
int main(){
	long long n,L=0,o=0,ans=0,Lh;
	char s[1000000];
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=0;j<a;j++){
			s[o++]=c;
		}
		L+=a;
	}
	if(L%2==0) Lh=L/2;
	else Lh=L/2+1;
	for(long long i=0;i<Lh;i++){
		if(s[i]!=s[L-1-i]) ans++;
	}
	printf("%lld",ans);
	return 0;
}

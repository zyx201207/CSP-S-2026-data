#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b;
	long long n=0,m=0;
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		char c='0';
		scanf("%lld %c",&m,&c);
		for(long long j=0;j<m;j++){
			a.insert(a.end(),c);
		}
	}
	for(int i=a.length();i>0;i--){
		b+=a[i-1];
	}
//	cout<<a<<"  "<<b;
	long long sum=0;
	for(long long i=0;i<a.length()/2;i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	printf("%lld",sum);
	return 0;
}

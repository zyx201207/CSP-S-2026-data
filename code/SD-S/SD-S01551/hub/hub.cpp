#include<bits/stdc++.h>
using namespace std;
long long qkread() {
	long long n1=0,qkf=1;
	char qkc=getchar();
	while(qkc<'0'||qkc>'9') {
		if(qkc=='-') qkf=-1;
		qkc=getchar();
	}
	while(qkc>='0'&&qkc<='9') {
		n1=n1*10+qkc-48;
		qkc=getchar();
	}
	return n1*qkf;
}
long long c,T,n,K,U,V;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=qkread(),T=qkread();
	while(T--) {
		n=qkread(),K=qkread();
		for(int i=1; i<n; i++) U=qkread(),V=qkread();
		cout<<(int)(ceil((double)(n-K)/(K+1)))<<"\n";
	}
	return 0;
}

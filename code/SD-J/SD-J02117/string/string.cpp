#include<bits/stdc++.h>
using namespace std;
struct x{
	long long c;
	char d;
	
};
x a[2000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	cin>>n;
	string b;
	long long f=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i].c >>a[i].d;
		for(long long  j=1;j<=a[i].c;j++){
			b+=a[i].d;
		}
		s+=a[i].c;
	}
	for(long long i=0;i<s/2;i++){
		if(b[i]!=b[s-i-1]) f++;
	}
	cout<<f;
	return 0;
}

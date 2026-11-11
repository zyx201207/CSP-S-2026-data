#include <iostream>
using namespace std;
int main() {
	string s,t;
	long long n,a,l = 0,h= 0,b =0;
	char c;
	cin>>n;
	for(long long i = 1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(long long j = 1;j<=a;j++){
			s+=c;
		}
	}
	int f= 1;
	if(l%2 ==0){
		l = l/=2;
		f = 0;
	}
	else{
		l-=1;
		l/=2;
	}
	for(long long k = l;k>=1;k--){
			t+=s[k-1];
	}
	for(long long h = 0;h<=l;h++){
		if(s[l+h+f] !=t[h]){
			b++;
		}
	}
	cout<<b;
	return 0;
}

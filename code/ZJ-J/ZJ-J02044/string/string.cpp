#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
char s[N+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,p=1,z=0;
	cin>>a;
	for(long long i=1;i<=a;i++){
		long long b;
		char c;
		cin>>b>>c;
		for(long long j=p;j<=b+p;j++){
			s[j]=c;
		}
		p+=b;
	}

	for(long long i=1;i<=p/2;i++){
		if(s[i]!=s[p-i]) z++;
	}
	cout<<z;
	return 0;
}
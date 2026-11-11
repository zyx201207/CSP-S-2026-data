#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N],s1[N/2],s2[N/2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	long long x;
	char c;
	long long n=0;
	bool b=0;
	for(long long i=1;i<=a;i++){
		cin>>x>>c;
		n+=x;
		char cc;
		if(i!=1&&cc!=c)b=1;
		else if(i==1)cc=c;
	}
	if(!b)cout<<0;
	else cout<<n/2;
	return 0;
}

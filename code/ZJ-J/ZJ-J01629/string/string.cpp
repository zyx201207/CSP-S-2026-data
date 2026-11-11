#include<bits/stdc++.h>
using namespace std;
char s[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t,c;
	t=0;c=0;
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char r;
		cin>>a>>r;
		for(long long j=1;j<=a;j++){
			s[++t]=r;
		}
	}
	for(long long i=1;i<=t/2;i++){
		if(s[i]!=s[t-i+1]){
			c++;
		}
	}
	cout<<c;
	return 0;
}

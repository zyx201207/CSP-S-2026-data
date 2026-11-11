#include<bits/stdc++.h>
using namespace std;
const long long N=1e11+10;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long m=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			c[m]=b;
			m++;
		}
	}
	long long sum=0;
	long long x=1;
	long long y=m-1;
	for(long long i=1;i<=m/2;i++){
		if(c[x]!=c[y]) sum++;
		x++;
		y--;
	}
	cout<<sum;
	return 0;
} 

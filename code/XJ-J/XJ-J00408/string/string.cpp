#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0;
	for(long long i=1;i<=n;i++){
		long long b;
		cin>>b;
		sum+=b;
		char c;
		cin>>c;
		int d=c-'a';
		for(long long j=sum-b;j<sum;j++){
			a[j]=c;
		}
	}
	long long s=0;
	for(long long i=0;i<sum/2;i++){
		if(a[i]!=a[sum-i-1])s++;
	}
	cout<<s;
	return 0;
}
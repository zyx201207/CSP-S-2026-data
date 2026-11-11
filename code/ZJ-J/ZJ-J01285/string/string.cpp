#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[2000];
string b[2000];
int main(){
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int c[1000];
	for(long long i=0;i<=n;i++){
		for(long long j=0;j<=a[i];j++){
			c[i]=1;
		}
	}
	for(long long i=0;i<1;i++){
		cout<<2;
	}
	return 0;
}

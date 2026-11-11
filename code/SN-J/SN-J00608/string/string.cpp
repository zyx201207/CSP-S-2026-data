#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,j=1;
    long long a[10000000000];
	string c;
	char b;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b;
		for(j;j<=a[i];j++){
			c[j]=b;
		}
	}
	cout<<j;
	return 0;
}

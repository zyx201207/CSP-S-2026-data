#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
unsigned long long sum=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		char x;
		cin>>a[i]>>x;
		b[i]=x-'a';
		c[n+1-i]=a[i];
	}
	for(int i=1; i<=n; i++) {
		if(a[i]!=c[i]  || ((i!=n/2)  && b[i]!=b[n+1-i]) )
		sum+=b[i];
	}
	cout<<sum;
	return 0;
}

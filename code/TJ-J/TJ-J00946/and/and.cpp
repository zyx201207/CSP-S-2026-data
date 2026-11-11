#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
long long b[100000005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	string c;
	int js=1;
	for(int i=1; i<=n; i++) {
		long long ts=a[i];
		long long tss=ts;
		for(int j=1; j<=tss; j++) {
			b[j]=ts%2;
			ts=ts/2;
		}
		reverse(b+1,b+1+tss);
		c[i]=b[i]+' ';
		c[ts+1]=' ';
		for(int j=1;j<=c.size();j++){
			if(c[j]==' '){
				string b[j]=c.substr(js,j);
				js+=ts;
			}
		}
	}
	cout<<a[n];
	return 0;
}

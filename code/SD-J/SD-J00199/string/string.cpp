#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	string c;
	long long n,b[n];
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>b[i];
		cin>>a[i];
	}
	for (int i=n-1;i>=0;i--){
		c[n-i]=a[i];
	}
	int num=0;
	for (int i=0;i<n;i++){
		if (c[i]!=a[i]){
			num+=b[i];
		}
	}
	cout<<num;
	return 0;
} 

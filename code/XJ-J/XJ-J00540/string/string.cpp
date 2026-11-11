#include<bits/stdc++.h>
using namespace std;
	long long a[100000000];
	char b[100000];
	char d[100000];
	char e[100000];
	char z[100000];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int c;
	int f;
	int len=0;
	int h;
	int g;
	int cnt=0;
	cin>>c;
	for(int i=0; i<c; i++) {
		cin>>a[i]>>b[i];
	}
	for(int k=0; k<c; k++) {
		for(int i=0; i<a[k]; i++) {
			d[len]=b[k];
			len++;
		}
	}
	h=strlen(d);
	f=(strlen(d))/2;
	g=(strlen(d)-1)/2;
	if(strlen(d)%2==0) {
		for(int i=0; i<f; i++) {
			e[i]=d[i];
			if(e[i]!=d[h-i-1]) {
				cnt++;
			}
		}
	} else {
		for(int i=0; i<=g; i++) {
			z[i]=d[i];
			if(z[i]!=d[h-i-1]) {
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
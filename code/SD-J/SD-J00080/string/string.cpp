#include<bits/stdc++.h>
using namespace std;
char a[200005];
char b[200005];
long long x;
char s;
long long n;//1000000000
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int len=1;
	for(long long i=1; i<=n; i++) {
		cin>>x>>s;
		for(long long j=1; j<=x; j++) {
			a[len]=s;
			len++;
		}
	}
	len--;
	long long hou=len/2+1;
	long long cnt=1;
	for(long long i=len; i>=hou; i--) {
		b[cnt]=a[i];
		cnt++;
	}
	long long num=0;
	if(len%2==1) {
		hou++;
	}
	for(int i=1; i<hou; i++) {
		if(a[i]!=b[i]) {
			num++;
		}
	}
	cout<<num;
	return 0;
}

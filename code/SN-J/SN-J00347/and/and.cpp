#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[200010];
int read() {
	int f=1,ans=0;
	char ch=getchar();
	if(!isdigit(ch)) {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=0; i<n; i++) {
		a[i]=read();
	}
	if(m==1) {
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	if(m==n) {
		cnt=a[0];
		for(int i=0; i<n; i++) {
			cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==n-1) {
		sort(a,a+n);
		cnt=a[n-1]&a[n-2];
		cout<<cnt;
		return 0;
	}
	cout<<0;
	return 0;
}

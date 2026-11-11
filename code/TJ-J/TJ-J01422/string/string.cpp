#include<bits/stdc++.h>

using namespace std;

struct uu{
	int x;
	char c;
}a[200010];
int n;
long long h;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].c;
	}
	for(int i=1,j=n;i<j;) {
		int t=min(a[i].x,a[j].x);
		a[i].x-=t;
		a[j].x-=t;
		if(a[i].c!=a[j].c) h+=t;
		if(a[i].x==0) i++;
		if(a[j].x==0) j--;
	}
	cout<<h;
	return 0;
}

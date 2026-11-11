#include<bits/stdc++.h>
using namespace std;
long long n;
struct ccr {
	int a;
	char c;
} a[2000007];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].a>>a[i].c;
	}
	long long l=1,r=n,sum=0;
	while(l<r) {
		int cha=min(a[l].a,a[r].a);
		a[l].a-=cha;
		a[r].a-=cha;
		if(a[l].c!=a[r].c) {
			sum+=cha;
		}
		if(a[l].a==0)
			l++;
		if(a[r].a==0)
			r--;
	}
	cout<<sum;
	return 0;
}

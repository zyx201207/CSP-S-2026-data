#include<bits/stdc++.h>
using namespace std;
//long long aaa[100000000],b[100000000];
long long n,numm,cnt;
struct aa{
	long long num;
	char s;
}a[500005];
bool cmp (aa b,aa c) {
	return b.num>c.num;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i].num>>a[i].s;
		numm+=a[i].num;
	}
	if (n<=1) {
		cout<<0;
		return 0;
	}
	if (n==2) {
		if (a[1].num==a[2].num) {
			cout<<0;
			return 0;
		}
		if (a[1].num>a[2].num){	
			cout<<a[2].num;
			return 0;
		} else {
			cout<<a[1].num;
			return 0;	
		}
	}
	sort(a+1,a+n+1,cmp);
	for (int i=2;i<=n;i++) {
		cnt+=a[i].num;
	}
	cout<<cnt;
	
	return 0;
}
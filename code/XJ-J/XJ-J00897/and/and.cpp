#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (m==1) {
		cout<<a[m];
		return 0;
	}
	if (m==n) {
		int cnt=a[1];
		for (int i=2;i<=m;i++) {
			cnt&=a[i];
		}
		cout<<cnt;
	}
	if (n-1==m) {
		int cnt=a[2];
		for (int i=3;i<=m;i++) {
			cnt&=a[i];
		}
		cout<<cnt;
	}
	int maxin=-1;
	for (int i=1;i<=n;i++) {
		for (int z=i;z<=m;z++) {
			int num=a[i];
			num&=a[z];
			maxin=max(maxin,num);
		}
	}
	
	cout<<maxin;
	
	return 0;
}
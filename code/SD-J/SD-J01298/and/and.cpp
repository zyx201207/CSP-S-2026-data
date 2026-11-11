#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005],n,m,d;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if (m==1){
		cout<<a[n];
		return 0;
	}
	if (m==n){
		int d=a[1];
		for (int i=2;i<=n;i++){
			d=d&a[i];
		}
		cout<<d;
		return 0;
	}
	int f=a[n];
	for (int i=n;i>=n-m+1;i--){
		f=f&a[i];
	}
	int e=a[1];
	for (int i=1;i<=m;i++){
		e=e&a[i];
	}
	cout<<max(f,e);
	return 0;
}

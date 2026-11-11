#include <bits/stdc++.h>>
using namespace std;
int n,m,ans=1;
bool than (long long a,long long b){
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,than);
	for(int i=1;i<=m;i++){
		a[1]=a[1]&a[i];
	}
	cout<<a[1];
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0;
	b=a[m];
	for(int i=m;i>=n-m;i--)
	{
		b&=a[i];
	}
	cout<<b;
	return 0;
}

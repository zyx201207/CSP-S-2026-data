#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int n;
long long a[N];
bool check1()
{
	int i;
	for(i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i+1]-a[i]) return 0;
	}
	return 1;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,i;
	long long d;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++) cin>>a[i];
		if(check1()) cout<<n*(n-1)/2<<"\n";
		else cout<<"0\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[500086];
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma+=a[i];
	}
	cout<<ma/n;
}

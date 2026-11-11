#include<bits/stdc++.h>
using namespace std;
long long s[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,i,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	cout<<s[n];
	return 0;
}

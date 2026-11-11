#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[210000],k,k1,k2;
char c[210000];
string ss;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		k+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			ss+=c[i];
		}
	}
	for(int i=1;i<=k/2;i++)
	{
		if(ss[i-1]!=ss[k-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

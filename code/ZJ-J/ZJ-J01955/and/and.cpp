#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[100001],m,ma=-1e9,b[1000001],k,mx=-1e9;
string s[1000001],la;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<i;j++)
		{
			if(a[j]==a[i])
			{
				mx=max(mx,a[i]);
			}
		}
	}
	if(mx==-1e9)
	{
		cout<<a[n-m+1];
	}
	else
	{
		cout<<mx;
	}
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=5e5+10;
ll n,m;
ll maxn,maxxn;
ll a[MAX_N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
	}
	else{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				maxxn=max(a[i]&a[j],maxxn);
			}
		}
		cout<<maxxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

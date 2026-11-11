#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long val[500005];
int main()
{
		ios::sync_with_stdio(false);
		cin.tie(0);
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
				cin>>a[i];
		}
		sort(a + 1,a + n + 1);
		for(int i=2;i<=n;i++)
		{
			val[i] = (i - 1) * (a[i] - a[i - 1]) + val[i - 1];
			if(val[i] > m)
			{
				cout<<i - 1;
				return 0;
			}
		}
		cout<<"0";
		return 0;
}

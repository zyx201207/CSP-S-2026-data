#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0;
long long z[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>z[i];
	sort(z+1,z+n+1);
	for(int i=n;i>=1;i--)
	{
		long long a=i,si=1,sn=0;
		while(a--)
		{
			if(z[i]-z[a]+sn<=m)
			{
				si++;
				sn=sn+z[i]-z[a];
			}
			else a=0;
		}
		if(s<si) s=si;
	}
	cout<<s;
	return 0;
}

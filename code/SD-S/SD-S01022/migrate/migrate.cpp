#include<bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		long long d;
		int n,a[200100],s[200100],sum=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		s[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			cout<<abs(s[sum]-a[i])<<endl;
			if(abs(s[sum]-a[i])<=d) s[++sum]=a[i];
			else continue;
		}
	}
	return 0;
}

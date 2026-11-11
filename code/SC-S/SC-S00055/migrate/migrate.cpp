#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10; 
ll a[N],s[10005][10005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				s[i][j]=(a[j]-a[i]+d-1)/d;
			}
		}
	}
	return 0;
}
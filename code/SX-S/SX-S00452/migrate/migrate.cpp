#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],l1[N];
long long n,d,ans;
void pd(int l,int r,int lj)
{
	if(l==r)
	{
		l1[lj]++;
		return;
	}
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]-a[l]<=d)
		{
			pd(i,r,lj+1);
		}
		else
		{
			return;
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long l=1;l<=n;l++)
		{
			for(long long r=l+1;r<=n;r++)
			{
				memset(l1,0,sizeof(l1));
				pd(l,r,0);
				for(int i=1;i<=r-l;i++)
				{
					if(l1[i]==0) continue;
					if(l1[i]==2) ans++;
					else break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
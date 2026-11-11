#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],ans,b[N],ll;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int j=30;j>=0;j--)
	{
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(((a[i]>>(j))&1)==1)
			{
				k++;
			}
		}
		if(k>1)
		{
			for(int i=1;i<=n;i++)
			{
				if(((a[i]>>(j))&1)==1)
				{
					b[++ll]=a[i];
					a[i]=0;
				}
			}
		}
	}
	ans=b[1];
	for(int i=2;i<=m;i++)
	{
		ans=(ans&b[i]);
	}
	cout<<ans;
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
const int C=31;
int n,m,ans,cnt;
int a[N],b[N][C],mi[C];
bool vis[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	mi[0]=1;
	for (int i=1;i<C;i++)
		mi[i]=mi[i-1]*2;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i]=true;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		for (int j=C-1;j>=0;j--)
		{
			b[i][j]=a[i]/mi[j];
			a[i]-=b[i][j]*mi[j];
		}
	for (int j=C-1;j>=0;j--)
	{
		cnt=0;
		for (int i=n;i>=1;i--)
			if (vis[i] and b[i][j]==1)
				cnt++;
		if (cnt>=m)
		{
			for (int i=n;i>=1;i--)
				if (b[i][j]==0)
					vis[i]=false;
			ans+=mi[j];
		}
	}
	cout<<ans<<"\n";
	return 0;
} 

#include<iostream>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
bool is[N][32];
bool f[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k;
	for(int i=1;i<=n;i++)
	{
		k=a[i];
		for(int j=30;j>=0&&k!=0;j--)
		{
			if(k>=(1<<j)) is[i][j]=1,k-=(1<<j);
		}
	}
	int cnt;
	for(int j=30;j>=0;j--)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]) continue;
			if(is[i][j]) cnt++;
		}
		if(cnt>=m)
		{
			ans+=(1<<j);
			for(int i=1;i<=n;i++)
			{
				if(!is[i][j]) f[i]=true;
			}
		}
	}
	cout<<ans;
	return 0;
}

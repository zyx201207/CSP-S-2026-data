#include<bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;
int n;
int a[N][32],s[N];
int m;
int ans[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][31];
		int temp=a[i][31];
		int k=0;
		while(temp)
		{
			a[i][k++]=temp%2;
			temp/=2;
			s[k-1]+=a[i][k-1];
		}
	}
//	cout<<"---------------\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<31;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<"\n";
//	}
//	cout<<"--------------\n";
	for(int i=30;i>=0;i--)
	{
/*//			cout<<"---------------\n";
//cout<<i<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<31;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<"\n";
//	}
//	cout<<"--------------\n";*/
		if(s[i]>=m)
		{
			ans[i]=1;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0)
				{
					a[j][31]=0;
				}
			}
			memset(s,0,sizeof(s));
			for(int j=1;j<=n;j++)
			{
				int temp=a[j][31];
				int k=0;
				while(temp)
				{
					a[j][k++]=temp%2;
					temp/=2;
					s[k-1]+=a[j][k-1];
				}
			}
		}
	}
	int cnt=0;
	for(int i=30;i>=0;i--)
	{
//		cout<<ans[i];
		cnt=cnt*2+ans[i];
	}
	cout<<cnt;
	return 0;
}

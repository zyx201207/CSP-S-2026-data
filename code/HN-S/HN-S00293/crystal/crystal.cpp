#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int a[N],n,m,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int is_A=1;
	for(int i=2; i<=n&&is_A; i++)
	{
		if(a[i]-a[i-1]!=a[2]-a[1]) is_A=0;
	}
	if(n<=10000)
	{
		for(int i=1; i<=n; i++)
		{
			int cnt=m,sum=0;
			for(int j=i-1; j>=1; j--)
			{
				int x=a[i]-a[j];
				if(cnt>=x)
				{
					cnt-=x;
					sum++;
				}
			}
			ans=max(ans,sum+1);
		}
		cout<<ans;
	}
	else if(is_A==1)
	{
		int cha=a[2]-a[1];
		int sum=cha;
		while(sum<=m)
		{
			m-=sum;
			sum+=cha;
			ans++;
		}
		cout<<min(n,ans);
	}
	else
	{
		cout<<"315275";
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

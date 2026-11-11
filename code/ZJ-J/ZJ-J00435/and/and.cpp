#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
int b[200005][35];
int ans[35];
int flag[200009];
long long sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		flag[i]=1;
		int t0=a[i],l=0;
		while(t0)
		{
			b[i][++l]=t0%2;
			t0/=2;
		}
	}
	for(int w=30;w>=1;w--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!flag[i])continue;
			cnt+=b[i][w];
		}
		if(cnt<m)
		{
			ans[w]=0;
			continue;
		}
		ans[w]=1;
		for(int i=1;i<=n;i++)
		{
			if(!b[i][w])
			{
				flag[i]=0;
			}
		}
	}
	for(int w=30;w>=1;w--)
	{
		if(ans[w])
		{
			sum+=(1<<(w-1));
		}
	}
	cout<<sum;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=35;
const int N=2e5+10;
int t[N],a[N][M],cnt[N][M],pos[M];//cnt[i][j]:前i个数，第j位有多少个为1
bool flag[N]; 
//pos[j]:第一个出现第j位为0的位置 
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,lenmax=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>t[i];
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int x=t[i],len=0;
		for(int j=0;(1<<j)<=x;j++)
		{
			len++;
			if((1<<j)&x) a[i][len]=1;
			else a[i][len]=0;
		}
		if(i==1) lenmax=len;
		/*
		for(int j=lenmax;j>=1;j--)
		{
			if(a[i][j]==1)
			{
				cnt[i][j]=cnt[i-1][j]+1;
			}
			else
			{
				cnt[i][j]=cnt[i-1][j];
				if(pos[j]==0) pos[j]=i;
			}
		}
		*/
	}
	
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=lenmax;j>=1;j--)
		{
			cout<<cnt[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	int ans=0;
	for(int j=lenmax;j>=1;j--)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]==1 && !flag[i]) tot++;
		}
		if(tot>=m)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i][j]==0) flag[i]=true;
			}
			ans+=(1<<(j-1));
		}
	}
	cout<<ans<<endl;
	return 0;
}

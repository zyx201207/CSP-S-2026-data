#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],mem[20005][20005];
int dp(int pos,int num)
{
	if(pos==n+1)
	{
		return -1;
	}
	if(mem[pos][num]!=-1)
	{
		return mem[pos][num];
	}
	int ans=dp(pos+1,num);
	if(num-1>=0)
	{
		int ma=0,d=dp(pos+1,num-1);
		if(d==-1)
		{
			ma=a[pos];
		}
		else
		{
			ma=d;
		}
		ans=max(ans,ma&a[pos]);
	}
	mem[pos][num]=ans;
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(mem,-1,sizeof(mem));
	cout<<dp(0,m);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long a[200010],b[200010][32],c[32],n,m,ans;
bool f[200010];
string s;
void an(long long a,int ai)
{
	int k=0;
	while(a>0)
	{
		int ans=(a%2);
		b[ai][k]+=ans;
		c[k]+=ans;
		k++;
		a/=2;
	 } 
}
void deat(int ai)
{
	for(int i=1;i<=n;i++)
	{
		if(!b[i][ai]&&!f[i])
		{
			f[i]=true;
			for(int j=0;j<=ai;j++)
			{
				c[j]-=b[i][j];
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		an(a[i],i);
	}
	for(int i=30;i>=0;i--)
	{
		if(c[i]>=m)
		{
			deat(i);
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}

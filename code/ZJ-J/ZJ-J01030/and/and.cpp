#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long a[200005];
bool visited[200005];
unsigned long long andop(unsigned long long a,unsigned long long b)
{
	unsigned long long ret=0;
	unsigned long long s=1;
	while(a!=0||b!=0)
	{
		if(a%2==1&&b%2==1)
		{
			ret=ret+s;
		}
		s*=2;
		a=a>>1;
		b=b>>1;
	}
	return ret;
}
unsigned long long solve(int m)
{
	//cout<<"solve:"<<m<<endl;
	unsigned long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			//cout<<"i="<<i<<endl;
			if(m==2)
			{
				visited[i]=true;
				//cout<<"solve#1"<<endl;
				for(int j=1;j<=n;j++)
				{
					//cout<<"j="<<j<<endl;
					if(!visited[j])
					{
						ans=max(ans,andop(a[i],a[j]));
						//cout<<"ans="<<ans<<endl;
					}
				}
				visited[i]=false;
			}
			else
			{
				visited[i]=true;
				ans=max(ans,andop(a[i],solve(m-1)));
				visited[i]=false;
			}
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//cout<<andop(a[i],a[i])<<endl;
	}
	cout<<solve(m);
}

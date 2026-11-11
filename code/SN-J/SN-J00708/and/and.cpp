//李泽畅 西安市莲湖区庆安中学 SN-J00708 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200005],b[200005];
void dfs(int dep,int f)
{
	if(dep>n)
	{
		if(f==m)
		{
			int ans=0;
			bool ok=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==1&&ok==0)
				{
					ans=a[i];
					ok=1;
				}
				if(b[i]==1)
				{
					ans=ans&a[i];
				}
			}
			cout<<ans<<endl;
		}
		return ;
	}
	dfs(dep+1,f);
	b[dep]=1;
	dfs(dep+1,f+1);
	b[dep]=0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0);
	return 0;
	
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+15;
int n,m;
int a[N];
int b[N];
int lst[N];
int ans[N];
bool vis[N];
int mp[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	// 10:13 start reading T4 
	// 10:40 coding T4 24pts solution
	// 11:44 finish 24pts solution
	// 11:47 finish 32pts solution
	// 11:49 finish 48pts solution
	// ji xian ha ha ha 
	// 100+100+100+48=348 good but not very perfect
	// ke wu de T2 ka le wo 1 xiao shi
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!lst[a[i]]) lst[a[i]]=i;
		else b[i]=lst[a[i]],lst[a[i]]=i; 
	}
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				mp[a[j]]=0;
				vis[j]=0;
			}
			for(int j=i;j<=n;j++)
			{
				if(mp[a[j]]==1 && vis[b[j]])
				{
					for(int k=b[j];k<=j-1;k++)
					{
						if(vis[k])
						{
							mp[a[k]]--;
							vis[k]=0;
						}
					}	
				}	
				mp[a[j]]++;
				vis[j]=1;
			}	
			for(int j=i;j<=n;j++)
			{
				if(vis[j]) ans[a[j]]++; 
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else if(m==2)
	{
		if(a[n]==1)
		{
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==2) tot++;
			}
			cout<<n<<" "<<tot<<endl;
		}
		else
		{
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) tot++;
			}
			cout<<tot<<" "<<n<<endl;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				cout<<i<<" ";		
			}
		} 
		cout<<endl;
	}
} 

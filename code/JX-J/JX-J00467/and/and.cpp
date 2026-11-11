#include <bits/stdc++.h>
using namespace std;
map<int,int> t;
int n,m;
int a[200010];
bool vis[200010];
int maxx=-1;
void dfs(int cnt,int sum)
{
   if(cnt==m)
   {
	   maxx=max(maxx,sum);
	   return ;
   }
   for(int i=1;i<=n;i++)
   {
		if(!vis[i])
		{
			vis[i]=1;
			dfs(cnt+1,sum&a[i]);
			vis[i]=0;
		}
   }
}	
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
 cin>>a[i];	
}
if(n<=20)
{
for(int i=1;i<=n;i++){
	vis[i]=1;
	dfs(1,a[i]);
	vis[i]=0;
}
cout<<maxx;
return 0;
}
else if(n<=2000)
{
	if(m==1)
	{
	 sort(a+1,a+1+n);
	 cout<<a[n];	
	}else if(m==n)
	{
		maxx=a[1];
		for(int i=1;i<=n;i++)
		{
			maxx=maxx&a[i];
		}
			cout<<maxx;
			return 0;
	}else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx;
		return 0;
	}
}
return 0;
}

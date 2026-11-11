#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m,a[200010];
unsigned long long maxx=-1;
unsigned long long sum=0;
bool ok=false;
unsigned long long ans=-1;
void dfs(int now,int start)
{
	if(now>m)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=start;i<=n;i++)
	{
		if(now==1)
		{
			sum=a[i];
			dfs(now+1,i+1);
			sum=0;
		 } 
		 else
		 {
		 	int last=sum;
		 	sum&=a[i];
			dfs(now+1,i+1);
			sum=last;
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
		maxx=max(maxx,a[i]);
		if(!ok)
		{
			ok=true;
			sum=a[i];
		}
		else
		{
			sum&=a[i];
		}
	 } 
	 if(m==1)
	 {
	 	cout<<maxx;
	 	return 0;
	 }
	 if(m==n)
	 {
	 	cout<<sum;
	 	return 0;
	 }
	 sum=0;
	 dfs(1,1);
	 cout<<ans;
	return 0;
 } 

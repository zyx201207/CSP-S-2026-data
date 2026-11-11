#include<bits/stdc++.h>
using namespace std;
long long num=0,sum=-1,a[1000000],m,n,s,mx,mmx,ok;
void dfs(int i)
{
	
	if(m==s)
	{
		sum=max(mx,sum);	s=0;
		//cot<<sum<<' '<<mx<<'\n';.
		return; 
	}
	if(i>=n)
	{
		return;
	}
	else
	{
		int x=mx;
		mx=(mx&a[i]);
		s++;
	//	cout<<a[i]<<'/';.
		dfs(i++);
		mx=x;
		s--;
		dfs(i++);
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
		mmx=max(mmx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		mx=a[i];
		dfs(1);
	//	cout<<"\n\n\n";.
	}
	cout<<mx;
}
--
#include<bits/stdc++.h>
using namespace std;  
int w,n,m,a[210000],sum,f[210000],ans,p[50];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y)
{
	if(x==m)
	{
		sum=max(sum,y);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0&&a[i]>sum)
		{
			f[i]=1;
			dfs(x+1,y&a[i]);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p[1]=1;
	for(int i=2;i<=30;i++) p[i]=p[i-1]*2;
	bool fff=0;
	for(int i=1;i<=20;i++) 
	{
		if(n==p[i]) 
		{
			fff=1;
			break;
		}
	}
	bool flag1=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ans=max(ans,a[i]);
		bool flag=0;
		for(int j=1;j<=30;j++) 
		{
			if(a[i]==p[j]-1) 
			{
				flag=1;
				break;
			}
		}
		if(flag==0) flag1=1;
	}
	int q=a[1];
	for(int i=2;i<=n;i++) q=q&a[i];
	if(m==1) 
	{
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		cout<<q;
		return 0;
	}
	if(m==2)
	{
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j) ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout<<ans1;
		return 0;
	} 
	sort(a+1,a+1+n,cmp);
	if(n<=20)
	{
		for(int i=1;i<=n;i++) 
		{
			memset(f,0,sizeof(f));
			if(sum<a[i]) f[i]=1,dfs(1,a[i]);
		}
		cout<<sum;
		return 0;
	}
	if(m==n-1)
	{
		int ww=a[1],l1=2,l2=3;
		while(l1<=n&&l2<=n)
		{
			if(ww&a[l1]>ww&a[l2])
			{
				ww&=a[l1];
				if(l1>l2) l1++;
				 else l1=l2+1;
			}
			else
			{
				ww&=a[l2];
				if(l2>l1) l2++;
				 else l2=l1+1;
			}
		}
		cout<<ww;
		return 0;
	}
	if(flag1==0||fff==1)
	{
		int kk=a[1];
		for(int i=2;i<=m;i++) kk&=a[i];
		cout<<kk;
		return 0;
	} 
	return 0;
}
/*
 
*/

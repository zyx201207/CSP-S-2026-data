#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10005],b[10005],c=1,d[10005],e; 
int prime(string u,string t)
{
	int ans1=0,ans2=0;
	string ans3=0;
	while(u)
	{
		ans1+=u%2+'0';
		u/=2;
	}
	while(v)
	{
		ans2+=v%2+'0';
		v/=2;
	}
	for(int i=0;i<max(ans1,ans2);i++)
	{
		if(u[i]==1&&v[i]==1)
		{
			ans3+='1';
		}
		else
		{
			ans3+='0';
		}
	}
	return reserve(ans3.begin(),ans3.end()-1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int num=0;
		string ans;
		cin>>a[i];
		d[i]=a[i];
		while(d[i])
		{
			ans+=d[i]%2+'0';
			d[i]/=2;
		}
		for(int x=0;x<ans.length();x++)
		{
			if(ans[x]='1')
			{
				num++;
			}
		}
		b[i]=num;
	}
	
	for(int j=1;j<=m;j++)
	{
		int maxn=-1000,pos=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]>maxn)
			{
				maxn=b[i];
				pos=i;
			}
		}
		e=prime(c,maxn);
		a[pos]=b[pos]=0;
	}
	cout <<e;
	
	return 0;
 } 

 


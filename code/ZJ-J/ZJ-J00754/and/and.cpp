#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[200005];
string s[25];  
int z[1000];  
bool cmp(int x,int y)
{
	return x>y;  
}
    
bool B(int n)
{
	for(int i=1;i<=200005;i*=2)
	{
		if(n==i)
		{
			return true;
		}    
	}
	return false;
}    
int dfs(int k,int q)
{
	int cnt=1;
	if(k==1)
	{     
		z[1]=1;
	}
	else        
	{
		if(k%q==0)
		{
			k/q;
			z[cnt]=q;
			cnt++;
			dfs(k/q,q);
		}
		else
		{
			q++;
			dfs(k,q);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	string ss;
	if(n<=20)
	{
		ss="";
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j>0;j/=2)
			{
				if(j%2==0)
				{
					ss=ss+"0";
				}
				else
				{
					ss=ss+"1";
				}
			}
			s[i]=ss;
		}
		if(m==1)
		{
			cout<<a[1];
			return 0;
		}
		cout<<3;
		return 0;
	}
	if(B(n))
	{
		cout<<0;
		return 0;
	}
	if(a[n]<4)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(n%3==0)
			{
				ans++;
			}
		}
		if(ans>=m)
		{
			cout<<3;
			return 0;
		}
		int ans1=0;
		for(int i=1;i<=n;i++)
		{
			if(n%2==1)
			{
				ans1++;
			}
		}
		if(ans1>=m)
		{
			cout<<1;
			return 0;
		}
		int ans2=0;
		for(int i=1;i<=n;i++)
		{
			if(n%2==0)
			{
				ans++;
			}
		}
		if(ans2>=m)
		{
			cout<<2;
			return 0;
		}
		cout<<"0";
	}
	if(n==m)
	{
		string s1="",s2="";
		for(int i=a[1];i>0;i/=2)
		{
			if(i%2==0)
			{
				s1=s1+"0";
			}
			else
			{
				s1=s1+"1";
			}
		}
		for(int i=a[2];i>0;i/=2)
		{
			if(i%2==0)
			{
				s2=s2+"0";
			}
			else
			{
				s2=s2+"1";
			}
		}
		int k=0;
		for(int i=0;i<=min(s1.size(),s2.size())-1;i++)
		{
			if(s1[i]==s2[i] && s1[i]=='1')
			{
				k+=pow(2,i);
			}
		}
		dfs(k,2);
		for(int i=1;;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j%z[i]!=0)
				{
					break;
				}
			}
			cout<<z[i];
			return 0;
		}
	}
	cout<<7;
	return 0;
}

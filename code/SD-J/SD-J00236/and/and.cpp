#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ma=-1;
long long ans=INT_MAX;
long long b[50];
string sa[200005];
long long str[1000];
long long c[200005];
string ark(int h)
{
	vector<int> g;
	while(h!=0)
	{
		g.push_back(h%2);
		h/=2;
	}
	string s="";
	for(int i=g.size()-1;i>=0;i--)
	{
		s+=g[i]+'0';
	}
	return s;
}
int stra=0;
int cntt=0;
bool cmp(int a,int b)
{
	string s1=ark(a),s2=ark(b);
	for(int i=1;i<=cntt;i++)
	{
		if(s1[s1.size()-str[i]-1]!=s2[s2.size()-1-str[i]])
		{
			return s1[s1.size()-str[i]-1]>s2[s2.size()-1-str[i]];
		}
	}
	return a<b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		ans=ans&a[i];
		string s=ark(a[i]);
		for(int j=s.size()-1;j>=0;j--)
		{
			b[s.size()-j-1]+=s[j]-'0';
		}
		sa[i]=s;
	}
	if(m==1)
	{
		cout<<ma;
	}
	else if(m==n)
	{
		cout<<ans;
	}
	else if(m==2&&n<=2000)
	{
		long long maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	else if(m==n-1)
	{
		long long maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<sa[i].size();j++)
			{
				b[j]-=sa[i][j]-'0';
			}
			long long ns=0;
			long long poww=1;
			for(int j=0;j<=30;j++)
			{
				if(b[j]==n-1)
				{
					ns+=poww;	
				}
				poww*=2;
			}
			maxx=max(maxx,ns);
			for(int j=0;j<sa[i].size();j++)
			{
				b[j]+=sa[i][j]-'0';
			}
		}
		cout<<maxx;
	}
	else
	{
		bool fff=false;
		for(int i=30;i>=0;i--)
		{
			if(b[i]>=m&&!fff)
			{
				stra=i;
				fff=true;
			}
			else if(fff)
			{
				str[++cntt]=i;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(sa[i].size()>stra)
			{
				if(sa[i][sa[i].size()-stra-1]=='1')
				{
					c[++cnt]=a[i];
				}
			}
		}
		sort(c+1,c+cnt+1,cmp);
		long long sum=INT_MAX;
		for(int i=1;i<=m;i++)
		{
			sum=sum&c[i];
		}
		cout<<sum;
	}
	return 0;
}
//nlogn多一点点
//空悲切 

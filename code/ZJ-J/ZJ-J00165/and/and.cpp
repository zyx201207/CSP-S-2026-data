#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
string s[200005];
map<int,int>mp;
string val;
int maxi;
string tt2(int x)
{
	string ans="";
	while(x>0)
	{
		ans.push_back('0'+x%2);
		x/=2;
	}
	return ans;
}
int tt10(string x)
{
	int ans=0;
	int pow=1;
	for(int i=0;i<x.size();i++)
	{
		ans+=(x[i]-'0')*pow;
		pow*=2;
	}
	return ans;
}
bool cmp(string x,string y)
{
	int xx=x.size(),yy=y.size();
	for(int i=(long long)(max(xx,yy))-1;i>=0;i--)
	{
		if(val[i]=='1')
		{
			if(i>=xx)
			{
				if(y[i]=='1')
				{
					return false;
				}
			}
			else if(i>=yy)
			{
				if(x[i]=='1')
				{
					return true;
				}
			}
			else
			{
				if(x[i]=='1'&&y[i]=='0')
				{
					return true;
				}
				else if(x[i]=='0'&&y[i]=='1')
				{
					return false;
				}
			}
		}
	}
	if(xx==yy)
	{
		for(int i=xx-1;i>=0;i--)
		{
			if(x[i]=='1'&&y[i]=='0')
			{
				return true;
			}
			else if(x[i]=='0'&&y[i]=='1')
			{
				return false;
			}
		}
	}
	else
	{
		return xx>yy;
	}
	return true;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int i,j;
	int maxn=-999;
	int maxx=0;
	int maxj=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=tt2(a[i]);
		mp[(long long)(s[i].size())]++;
		if(a[i]>maxn)
		{
			maxn=a[i];
			maxj=i;
		}
		//cout<<s[i]<<' ';
	}
	maxn=-999;
	for(i=1;i<=n;i++)
	{
		if(a[i]>maxn&&mp[s[i].size()]>=m)
		{
			maxn=a[i];
			maxi=i;
		}
	}
	if(maxi==0)val=s[maxj];
	else val=s[maxi];
	sort(s+1,s+n+1,cmp);
	/*for(i=1;i<=n;i++)
	{
		cout<<s[i]<<endl;
	}*/
	string ans;
	for(i=0;i<val.size();i++)
	{
		ans.push_back(val[i]);
		for(j=2;j<=m;j++)
		{
			if(s[j].size()<i+1)
			{
				ans[i]='0';
				break;
			}
			if(s[j][i]=='0')
			{
				ans[i]='0';
				break;
			}
		}
	}
	cout<<tt10(ans);
	return 0;
}

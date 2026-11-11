#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],len,maxx=INT_MIN;
long long ans=0;
string s[N],s1;
bool vis[N];
void dfs(int cs,int ans)
{
	if(cs==m)
	{
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(cs+1,ans&a[i]);
			vis[i]=0; 
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
		int t=a[i];
		while(t!=0)
		{
			s[i]=s[i]+char(t%2+'0');
			t/=2;
		}
		reverse(s[i].begin(),s[i].end());
		len=max(len,int(s[i].size()));
	}
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			dfs(0,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i].size()<len)
		{
			int t=len-int(s[i].size());
			for(int j=1;j<=t;j++)
			{
				s[i]="0"+s[i];
			}
		}
	}
	sort(s+1,s+1+n);
	s1=s[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		for(int j=0;j<s[i].size();j++)
		{
			if(s1[j]=='1'&&s[i][j]=='1')
			{
				s1[j]='1';
			}
			else
			{
				s1[j]='0';
			}
		}
	}
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s1.size();i++)
	{
		ans+=((s1[i]-'0')*pow(2,i));
	}
	printf("%lld",ans);
	return 0;
}

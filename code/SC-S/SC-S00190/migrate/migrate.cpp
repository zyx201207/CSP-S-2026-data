#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t,n,d,x[N],ans,ls;
bool f[N];
set<string> a;
string fun(int c)
{
	string r="";
	while(c!=0)
	{
		r=char(c%10+'0')+r;
		c/=10;
	}
	return r;
}
void dfs(int s,int e,int p,int k,string l)
{
	if(f[p])
	{
		return;
	}
	f[p]=1;
	if(p==e)
	{
		if(!a.count(l))
		{
			a.insert(l);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(p!=x[i])
		{
			if(abs(x[i]-x[p])<=d&&!f[i])
			{
				l+=fun(x[i]);
				dfs(s,e,i,k+1,l);
			}
		}
	}
	f[p]=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a.clear();
				ls=0;
				if(i==j)
				{
					continue;
				}
				dfs(x[i],x[j],x[i],0,fun(x[i]));
				int tt;
				for(set<string>::iterator i=a.begin();i!=a.end();i++)
				{
					string ttt=*i;
					if(i==a.begin())
					{
						tt=ttt.size();
					}
					if(i!=a.begin()&&ttt.size()==tt)
					{
						ls++;
					}
				}
				if(ls==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
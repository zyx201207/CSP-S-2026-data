#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,l;
struct hhj{
	int a;
	char c;
}s[N];
queue<int> zc,yc;
queue<char> t1,t2;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
		l+=s[i].a;
	}
	if(l<=1e8)
	{
		string t="";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=s[i].a;j++)
				t=t+s[i].c;
		}
		int mi=(l-1)/2,anrs=0;
		for(int i=0;i<=mi;i++)
		{
			if(t[i]!=t[l-i-1])
				anrs++;
		}
		cout<<anrs;
		return 0;
	}
	int m=n/2,res=0;
	for(int i=1;i<=m;i++)
	{
		hhj u=s[i],v=s[n-i+1];
		if(!zc.empty())
		{
			while(!zc.empty()&&u.a-zc.front()>=0)
			{
				if(u.c!=t1.front())
					res+=zc.front();
				u.a-=zc.front();
				zc.pop();
				t1.pop();
			}
			if(!zc.empty())
			{
				zc.front()-=u.a;
				zc.push(v.a);
				t1.push(v.c);
				continue;
			}
		}
		else if(!yc.empty())
		{
			while(!yc.empty()&&v.a-yc.front()>=0)
			{
				if(v.c!=t2.front())
					res+=yc.front();
				v.a-=yc.front();
				yc.pop();
				t2.pop();
			}
			if(!yc.empty())
			{
				yc.front()-=v.a;
				yc.push(u.a);
				t2.push(u.c);
				continue;
			}
		}
		if(u.a<=v.a)
		{
			zc.push(v.a-u.a);
			t1.push(v.c);
			if(v.c!=u.c)
				res+=u.a;
		}
		else if(u.a>v.a)
		{
			yc.push(u.a-v.a);
			t2.push(u.c);
			if(v.c!=u.c)
				res+=v.a;
		}
	}
	if(n%2==1)
	{
		if(yc.empty())
		{
			while(!zc.empty())
			{
				if(s[m+1].c!=t1.front())
					res+=zc.front();
				zc.pop();
				t1.pop();
			}
		}
		else if(zc.empty())
		{
			while(!yc.empty())
			{
				if(s[m+1].c!=t2.front())
					res+=yc.front();
				yc.pop();
				t2.pop();
			}
		}
	}
	cout<<res;
	return 0;
}


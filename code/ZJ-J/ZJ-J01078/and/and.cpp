#include<bits/stdc++.h>
using namespace std;
long long n,m,MAX=0;
struct node{
	long long a,b;
	string s;
}x[200005];
bool cmp(node aa,node bb)
{
	return aa.b>bb.b;
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
		cin>>x[i].a;
		x[i].b=x[i].a;
		MAX=max(MAX,x[i].a);
	}
	if(m==1)
	{
		cout<<MAX;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long cnt=-1,qp=0;
		while(1)
		{
			cnt++;
			qp=pow(2,cnt);
			if(qp>x[i].a)
			{
				break;
			}
		}
		if(pow(2,cnt)<=x[i].a)
		{
			x[i].a-=pow(2,cnt);
			x[i].s=x[i].s+'1';
		}
		for(int j=cnt-1;j>=0;j--)
		{
			if(pow(2,j)<=x[i].a)
			{
				x[i].a-=pow(2,j);
				x[i].s=x[i].s+'1';
			}
			else
			{
				x[i].s=x[i].s+'0';
			}
		}
	}
	sort(x+1,x+n+1,cmp);
	string as="";
	for(int i=2;i<=m;i++)
	{
		string as="";
		string ss=x[i-1].s,sss=x[i].s;
		if(ss.size()<sss.size())
		{
			for(int i=1;i<=sss.size()-ss.size();i++)
			{
				ss='0'+ss;
			}
		}
		else
		{
			for(int i=1;i<=ss.size()-sss.size();i++)
			{
				sss='0'+sss;
			}			
		}
		for(int i=0;i<ss.size();i++)
		{
			if(ss[i]==sss[i])
			{
				as=as+'1';
			}
			else if(i!=0)
			{
				as=as+'0';
			}
		}
		x[i].s=as;
	}
	long long sum=1;
	long long ans=0;
	for(int i=x[m].s.size()-1;i>=0;i--)
	{
		ans+=(x[m].s[i]-'0')*sum;
		sum*=2;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool c[200005][35];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//freopen("and5.in","r",stdin);
	//freopen("and5.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		string s="";
		int e=a[i];
		while(e)
		{
			char d=(e%2)+'0';
			s+=d;
			e/=2;
		}
		int f=0;
		for(int j=31;j>=1;j--)
		{
			if(f==s.size()) break;
			c[i][j]=s[f]-'0';
			f++;
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=31;j++) cout<<c[i][j];
		cout<<endl;
	}*/
	queue<int> q;
	int id=-1;
	for(int i=1;i<=31;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(c[j][i]) cnt++;
		}
		//cout<<cnt<<" ";
		if(cnt>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(c[j][i]) q.push(j);
			}
			id=i;
			break;
		}
	}
	//cout<<id<<endl;
	if(id==-1)
	{
		cout<<0;
		return 0;
	}
	string ans="1";
	for(int i=id+1;i<=31;i++) ans+='0';
	for(int i=id+1;i<=31;i++)
	{
		int cnt=0;
		queue<int> p;
		queue<int> g;
		while(q.size())
		{
			int t=q.front();
			q.pop();
			//cout<<t<<" ";
			p.push(t);
			if(c[t][i])
			{
				cnt++;
				g.push(t);
			}
		}
		//cout<<cnt<<" ";
		if(cnt>=m)
		{
			ans[i-id]='1';
			while(g.size())
			{
				int t=g.front();
				g.pop();
				q.push(t);
			}
		}
		else
		{
			while(p.size())
			{
				int t=p.front();
				p.pop();
				q.push(t);
			}
		}
		//cout<<ans<<endl;
	}
	long long sum=0;
	for(int i=0;i<ans.size();i++)
	{
		sum=sum*2+ans[i]-'0';
	}
	cout<<sum;
	return 0;
}
/*
4 2
3 15 12 12

12*/
/*
5 3
31 3 1 15 7

7*/

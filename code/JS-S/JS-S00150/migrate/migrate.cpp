#include<bits/stdc++.h>
using namespace std;

struct qu{
	int we;
	long long ch;
};

long long c,t,n,d,ans=0,po;
long long a[2000010];
queue<qu> q;

void bfs(long long x,long long y,long long len)
{
	while(!q.empty())
	{
		q.pop();
	}
	qu s;
	s.we=x;
	s.ch=len;
	q.push(s);
	int lea=0;
	while(!q.empty())
	{
		qu fro=q.front();
		q.pop();
		if(fro.we==y&&lea==fro.ch)
		{
			po=1;
			return;
		}
		if(fro.we==y&&lea==0)
			lea=fro.ch;
		int si=fro.we+1;
		while(a[si]-a[x]<=d && si<=y)
		{
			s.we=si;
			s.ch=fro.ch+1;
			q.push(s);
			si=si+1;
		}
	}
}

int main(){
	freopen("weimingming.in","r",stdin);
	freopen("weimingming.out","w",stdout);
	cin>>c>>t;
	for(int z=0;z<t;z++)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}

		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				po=0;
				bfs(i,j,0);
			}
			if(po==1)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

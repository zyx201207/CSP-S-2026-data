#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],as[N],an[N];
long long c,t,n,d,ans,ans1;
void bfs(int x)
{
	int b;
	queue<int> q,qb;
	q.push(x);
	qb.push(0);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		b=qb.front();
		qb.pop();
		for(int i=x+1;i<=n;i++)
		{
			if(a[i]-a[x]>d)
				break;
			q.push(i);
			qb.push(b+1);
			if(as[i]>b+1)
			{
				as[i]=b+1;
				if(an[i]==2)
					ans--;
				an[i]=0;
			}
			if(as[i]==b+1)
			{
				an[i]++;
				if(an[i]==2)
					ans++;
				else if(an[i]==3)
					ans--;
			}
		}
	}
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
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			memset(as,0x7f,sizeof(as));
			memset(an,0,sizeof(an));
			ans=0;
			bfs(i);
			ans1=ans+ans1;
		}
		cout<<ans1<<'\n';
	}
	return 0;
}
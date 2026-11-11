#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t;
int n;
long long d;
long long a[MAXN];
int rout[2000005];
long long dis[2000005];
struct P{
	int fir;
	int sec;
}p;
queue<P> que;
void bfs(int x)
{
	memset(rout,0,sizeof(rout));
	memset(dis,0,sizeof(dis));
	while(!que.empty()) que.pop();
	p.fir=x;
	p.sec=0;
	que.push(p);
	while(!que.empty())
	{
		P rec=que.front();que.pop();
		long long pos=a[rec.fir],t=rec.sec,num=rec.fir;
		if(dis[num]==0) dis[num]=t;
		if(t>dis[num]) continue;
		if(t==dis[num]) rout[num]++;
//		for(int i=rec.fir-1;pos-a[i]<=d&&i>=1;i--)
//		{
//			p.fir=i;
//			p.sec=t+1;
//			que.push(p);
//		}
		for(int i=rec.fir+1;a[i]-pos<=d&&i<=n;i++)
		{
			p.fir=i;
			p.sec=t+1;
			que.push(p);
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
		long long cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=1;j<=n;j++)
			{
//				cout<<rout[j]<<" ";
				if(rout[j]==2) cnt++;
			}
//			cout<<endl;
		}
		cout<<cnt<<endl;
	}	
	return 0;
}

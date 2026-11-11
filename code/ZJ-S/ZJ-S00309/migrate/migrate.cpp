#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define FRE freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
int read()
{
	int f=1;
	int k=0,c=getchar();
	for(;!isdigit(c);c=getchar())
		if(c=='-')
			f=-1;
	for(;isdigit(c);c=getchar())
		k=k*10+(c-'0');
	return k*f;
}
const int N=2e6+5,LOWN=5005;
int n;
int cnt[LOWN],cd[LOWN]; 
LL d;
LL x[N];
struct node {
	int v,w;
};

void solve(int c)
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	LL ans=0;
	for(int s=1;s<=n;s++)
	{ 
		queue<node> q;
		memset(cnt,0,sizeof(cnt));
		memset(cd,127,sizeof(cd));
		q.push((node){s,0});
		while(!q.empty())
		{
			int u=q.front().v;
			LL w=q.front().w;
			q.pop();
			if(w==cd[u])
				cnt[u]++;
			else
				if(w<cd[u])
					{
						cd[u]=w;
						cnt[u]=1;
					}
			for(int i=u+1;i<=n;i++)
			{
				if(x[u]+d<x[i])
					break;
				if(w+1<=cd[i])
					q.push((node){i,w+1});
			}
		}
		for(int j=s+1;j<=n;j++)
			if(cnt[j]==2)
				ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	FRE 
	int c,t;
	cin>>c>>t;
	while(t--)
		solve(c); 
	return 0;
} 

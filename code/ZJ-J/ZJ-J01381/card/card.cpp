#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],t[500005],nxt[500005],ans[500005];
int l,f[500005],p[500005],g[500005][2];
int sum[500005],c[500005],r[500005];
queue<int> q;
void work()
{
	for(int i=1;i<=n;++i)
		sum[i]=1;
	for(int i=n;i>=1;--i)
	{
		int d=i;
		if(p[i]==0){
			d=nxt[i];
		}
		else{
			d=p[i];
		}
		c[i]=d;
		r[d]++;
	}
	for(int i=1;i<=n;++i)
		if(!r[i])
			q.push(i);
	while(q.size())
	{
		int d=q.front();
		q.pop();
		if(d==n+1) continue;
		if((g[d][0]!=0)&&(g[d][1]!=0))
		{
			f[g[d][0]]+=sum[d];
			f[g[d][1]]-=sum[d];
		}
		r[c[d]]--;
		sum[c[d]]+=sum[d];
		if(r[c[d]]==0) q.push(c[d]);
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(t[a[i]]) p[t[a[i]]]=i;
		t[a[i]]=i;
	}
	l=0;
	for(int i=1;i<=n;++i){
		if(p[i]){
			for(int j=l;j<i;++j)
				nxt[j]=i;
			nxt[i]=i;
			l=i+1;
		}		
	}
	for(int i=l;i<=n;++i)
		nxt[i]=n+1;
	for(int i=1;i<=n;++i)
	{
		if(nxt[i]!=i)
		{
			g[i][0]=i;
			g[i][1]=nxt[i];
		}
	}
	work();
	for(int i=1;i<=n;++i)
	{
		f[i]+=f[i-1];
		ans[a[i]]+=f[i];
	}
	for(int i=1;i<=m;++i)
	{
		cout<<ans[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}

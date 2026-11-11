#include<bits/stdc++.h>
#define int long long
#define N 500100
using namespace std;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}return x*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}

int a[N];
int dp[N],fst[N];
int ans[N],fa[N],in[N];
queue<int>q;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		fst[a[i]]=i;
	}
	for(int i=n;i>=1;i--)
	{
		dp[a[i]]++;
		if(fst[a[i]]==i)
		{
			int u=a[i+1],v=a[i];
			fa[v]=u;
			in[u]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(in[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		dp[fa[v]]+=dp[v];
		in[fa[v]]--;
		if(in[fa[v]]==0)q.push(fa[v]);
	}
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]=dp[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<dp[i]<<' ';
	}
	return 0;
}


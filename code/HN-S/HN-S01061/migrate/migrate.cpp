#include<bits/stdc++.h>
#define int long long 
using namespace std;
int cid,T;
const int N=2e6+5;
const int NN=5e3+5;
int n,d;
int x[N],f[NN],num[NN];
int que[NN],fr,bk;
deque<int> dq[NN];
int Num[NN],Len[NN];
int cnt;
int read()
{
	char c=getchar_unlocked();
	int f=1,x=0;
	while(c<'0' or c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar_unlocked();
	}
	while(c>='0' and c<='9')
	{
		x=x*10+c-'0';
		c=getchar_unlocked();
	}
	return x*f;
}
void Clear()
{
	for(int i=1;i<=n;i++)
		f[i]=0,num[i]=0;
	fr=1,bk=0;
	for(int i=1;i<=cnt;i++)
		dq[i].clear(),Num[i]=0,Len[i]=0;
	cnt=0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cid=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		int ans=0;
		for(int i=1;i<=n;i++)
			x[i]=read();
		if(cid>=11 and cid<=12)
		{
			int cha=x[2]-x[1];
			if(d<cha*2){cout<<0<<'\n';continue;}
			else
			{
				cout<<max(0ll,n-(d/cha)*2+1)<<'\n';
				continue;
			}
		}
		for(int i=1;i<=n;i++)
		{
			Clear();
			que[++bk]=++cnt;
			Num[cnt]=1;Len[cnt]=0;
			dq[cnt].push_back(i);
			for(int j=i+1;j<=n;j++)
			{
				while(fr<=bk and x[dq[que[fr]].front()]<x[j]-d)
				{
					Num[que[fr]]-=num[dq[que[fr]].front()];
					dq[que[fr]].pop_front();
					if(!dq[que[fr]].size())
						++fr;
				}
				f[j]=Len[que[fr]]+1;
				num[j]=Num[que[fr]];
				if(num[j]==2) ans++;
				while(fr<=bk and Len[que[bk]]>f[j])
					bk--;
				if(fr<=bk and f[j]==Len[que[bk]])
					dq[que[bk]].push_back(j),Num[que[bk]]+=num[j];
				else Num[++cnt]=num[j],Len[cnt]=f[j],que[++bk]=cnt,dq[cnt].push_back(j);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
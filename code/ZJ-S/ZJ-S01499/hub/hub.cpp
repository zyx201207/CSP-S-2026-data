#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+8;
int t,c,n,k;
int head[MAXN],nxt[MAXN<<1],ed[MAXN<<1],ecnt;
inline void add(int u,int v) { ed[++ecnt]=v,nxt[ecnt]=head[u],head[u]=ecnt; }
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
	}
	return 0;
}
/*
离比赛结束还有大概30分钟,T4写不出来于是不写了.

我刚开始接触OI大概是在小升初的时候,当时只是把它当兴趣来学,没有什么天赋,也谈不上努力,因此也就是个半吊子的水平.
转眼间,三年时光飞逝而过,我的OI还是没有打出什么名堂,虽然由于优异的文化课被提前招走了不用担心中考,但我还是决定退役了.
再见了,我的OI生涯.

"一开始我没看到结果,我认为结果重要;
 再到我看到了结果,我认为过程重要;
 最后到我已经不在乎结果,我认为当下重要" 
							---来自某篇洛谷文章
							
AFOed.

luogu @chemical_reaction 
ZJ-S01499 && ZJ-J01437
*/

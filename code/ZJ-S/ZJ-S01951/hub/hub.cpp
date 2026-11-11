#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define rep1(i,x,y) for(int i=(x);i<=(y);i++)
#define rep2(i,x,y) for(int i=(x);i>=(y);i--)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define sp putchar(' ')
#define ln putchar('\n')
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')
int read(){
	char ch=getchar();
	bool p=0;
	int s=0;
	while(ch<'0'||ch>'9'){
		p=(ch=='-'?1:p);
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
		s=(s<<3)+(s<<1)+(ch^'0');
		ch=getchar();
	}return p?-s:s;
}void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}if(x>9)write(x/10);
	putchar(x%10|48);
}void fre(){freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);}
int ca;
namespace WinterAwOO{
	struct edge{int v,nxt;}e[2000010];
	struct node{
		int u,v,w;
		bool operator<(const node&t)const{return w<t.w;}
	}ee[16000010];
	int n,k,l,head[1000010],st[20][1000010],dfn[1000010],dep[1000010],id,a[1000010],ll,lll,s,fa[1000010];
	bool p[1000010];
	void ade(int u,int v){e[++l]={v,head[u]};head[u]=l;}
	int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
	void ad(int x,int y){fa[fd(y)]=fd(x);}
	int get(int x,int y){return dfn[x]<dfn[y]?x:y;}
	int getmin(int x,int y){int l=__lg(y-x+1);return get(st[l][x],st[l][y-(1<<l)+1]);}
	void initdfs(int x,int fa){
		dfn[x]=++id;
		st[0][id]=fa;
		dep[x]=dep[fa]+1;
		for(int i=head[x];i;i=e[i].nxt)
			if(e[i].v!=fa)initdfs(e[i].v,x);
	}int LC_A(int K,int IOI){
		if(K==IOI)return K;
		K=dfn[K];IOI=dfn[IOI];
		if(K>IOI)swap(K,IOI);
		return getmin(K+1,IOI);
	}int dfs(int x,int fa,int de){
		int mx=0;
		for(int i=head[x];i;i=e[i].nxt)
			if(e[i].v!=fa){
				int t=dfs(e[i].v,x,de);
				mx=max(mx,t);
			}
		if(mx==0)mx=de;
		if(mx==de*2){
			s++;
			p[x]=1;
			mx=0;
//			if(de==1)writeln(x);
		}return mx+1;
	}bool check(int x){
//		writeln(x);
//		puts("qwq");
		rep1(i,1,n)p[i]=0,fa[i]=i;
		s=0;
		int t=dfs(1,0,x);
		if(t>x+1)p[1]=1,s++;
//		if(x==1)writeln(t);
		if(s>k)return 0;
		ll=lll=0;
		rep1(i,1,n)
			if(p[i])a[++ll]=i;
//		rep1(i,1,ll)writesp(a[i]);
//		ln;
		if(ll<=2)return 1;
		int ss=0,sum=0;
		rep1(i,1,ll-1)
			rep1(j,i+1,ll){
				int t=LC_A(a[i],a[j]);
				if(dep[a[i]]+dep[a[j]]-2*dep[t]>1)ee[++lll]={a[i],a[j],dep[a[i]]+dep[a[j]]-2*dep[t]-1};
				else if(fd(a[i])!=fd(a[j])){
//					writesp(a[i]),writeln(a[j]);
					ss++;
					ad(a[i],a[j]);
					if(ss>=ll-2)return 1;
				}
			}
		sort(ee+1,ee+lll+1);
		rep1(i,1,lll)
			if(fd(ee[i].u)!=fd(ee[i].v)){
				ad(ee[i].u,ee[i].v);
				sum+=ee[i].w;
				ss++;
				if(s+sum>k)return 0;
				if(ss>=ll-2)return 1;
			}
		return 1;
	}signed main(int ID){
		n=read();k=read();
		l=0;
		rep1(i,1,n)head[i]=0;
		rep1(i,2,n){
			int u=read(),v=read();
			ade(u,v);
			ade(v,u);
		}if(k==n){
			puts("0");
			return 0;
		}if(ca==13||ca==14){
			n>>=1;
			if(k>=n){
				puts("1");
				return 0;
			}int s=1;
			while(n>0){
				n-=4;
				s++;
				if(k>=n){
					writeln(s);
					return 0;
				}
			}writeln(s);
			return 0;
		}initdfs(1,0);
//		puts("qwq");
		rep1(i,1,__lg(n))
			rep1(j,1,n-(1<<i)+1)st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
		int l=1,r=n,ans=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}else l=mid+1;
		}writeln(ans);
		return 0;
	}
}signed main(){
	fre();
	ca=read();
	int TTT=1;
	TTT=read();
	rep1(ttt,1,TTT)WinterAwOO::main(ttt);
	return 0;
}/*
[10,25]
总估分250pts。能七勾吗？

T4假了。我在写什么。我怎么想到写这唐玩意的。
T2都不会。
哦现在会了



福瑞很可爱！！！为什么要骂福瑞/fad
没错我是Furry控那咋了。
福瑞真的很可爱！！！/se/se/se

为什么考场C++只有光标在某一行的时候该行的汉字才显示得出来啊。有点烦。
想进迷惑行为大赏。
Luogu uid:1218338


freopen feropen freopne froepen freepon

还有10min。写不了暴力了。就这样吧。

求求了请不要挂分qaq

Staring at stars,
Watching the moon,
Hoping that one day they'll lead me to you.
Wait every night,
'Cause if a star falls,
I'll wish to go back to the time that I loved.
Why do the stars shine so bright in the sky
If most of the people are sleeping at night?
Why do we only have one chance at life?
I wish I could go back in time.

Pictures remind me of things I forgot,
But also of all of the things that I've lost.
Can't get them back, they won't fall from above,
So I try to forget all the times that I loved.
Why do we remeber beautiful lies?
We end up regretting them most of our lives.
Why do we only have one chance to try?
I wish I could go back in time.

Each Time I fall asleep,
I always see you there in my dreams.
It's like going back in a timemachine.
I know when I wake up the time with you will end.
So don't let me fall asleep,
I don't wanna meet you there in my dreams.
I know that we'll never build a timemachine.
It's time for me,
to try, and wake up again.

I fall asleep.
But honestly.
I wanna see,
You in my dreams.
I'm trying to wake up again.

CSP2026RP++!!!
*/
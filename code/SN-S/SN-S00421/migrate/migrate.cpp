#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int MAXN=2e6+5;
const int MAXM=5005; 
int c,t,n;
long long d,x[MAXN],ans=0;
struct tree
{
	struct point
	{
		int dp,cnt;	
	}tr[MAXM<<2];
	#define mid ((l+r)>>1)
	#define ls (i<<1)
	#define rs (i<<1|1)
	inline point marge(const point &a,const point &b)
	{
		point c=a;
		if(b.dp<a.dp) c=b;
		else if(c.dp==b.dp) c.cnt+=b.cnt;
		return c;
	}
	inline void up(int i) {tr[i]=marge(tr[ls],tr[rs]);}
	void Ibd(int i,int l,int r)
	{
		if(l==r) return tr[i]={n+1,0},void();
		Ibd(ls,l,mid),Ibd(rs,mid+1,r),up(i);
	}void bd(){Ibd(1,1,n);}
	void Iins(int i,int l,int r,int w,int dp,int c)
	{
		if(l==r) return tr[i]={dp,c},void();
		if(w<=mid) Iins(ls,l,mid,w,dp,c);
		else Iins(rs,mid+1,r,w,dp,c);
		up(i);
	}void ins(int w,int dp,int c) {Iins(1,1,n,w,dp,c);}
	point Iget(int i,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return tr[i];
		if(R<=mid) return Iget(ls,l,mid,L,R);
		if(mid<L) return Iget(rs,mid+1,r,L,R);
		return marge(Iget(ls,l,mid,L,R),Iget(rs,mid+1,r,L,R));
	}pair<int,int> get(int L,int R){point now=Iget(1,1,n,L,R);return {now.dp,now.cnt};} 
	#undef mid
	#undef ls
	#undef rs
}tr;

inline void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	
	if(c==11||c==12) // 性质 A 
	{
		if(n==1)
		{
			cout<<0<<endl;
			return ;
		}
		long long g=x[2]-x[1];
		if(d<=g)
		{
			cout<<0<<endl;
			return ;
		}
		d/=g;
//		cout<<d<<endl;
		cout<<max(0ll,n-2*d+1)<<endl;
		return ;
	}
	
	for(int i=1;i<=n;i++)
	{
		tr.bd();
		tr.ins(i,0,1);
		
		for(int j=i+1;j<=n;j++)
		{
			int l=i,r=j-1,k=-1;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(x[j]-x[mid]<=d) k=mid,r=mid-1;
				else l=mid+1; 
			}
			if(x[j]-x[k]>d) break;
			auto now=tr.get(k,j-1);
			tr.ins(j,now.fi+1,now.se);
			if(now.se==2) ans++; 
		}
	}
	
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(cin>>c>>t;t--;) solve();
	return 0;
} 

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
10 8
1 2 3 4 5 6 7 8 9 10

0 1
11 8
1 3 5 7 9 11 13 15 17 19 21

11 1
11 8
1 3 5 7 9 11 13 15 17 19 21

11 1
9 10000
-33 4444 8921 13398 17875 22352 26829 31306 35783

0 1
9 10000
-33 4444 8921 13398 17875 22352 26829 31306 35783

0 1
5 150
0 1 150 170 300

0 1
7 5
0 5 6 7 8 9 10

呀居然不考字符串
先来一个 n^3 dp 尝尝

想想 n^2 log 大概是线段树优化之类的，
但是就是说最大值我会最大值的 cnt 之和 我 也会 其实说这个
cnt是不是只有 1,2 两种状态啊（转移不到就重开一段） 
这应该是 正解的关键  
 
现在是 n*n*log 的了
开特殊性质 
 
A: 看了看

设公差为 g 首先只与 d/g 有关 
 
B 不会
C 应该是优化的看看 problem D吧 
 
*/

/*
暴力还是挺慷慨的，枚举出发点 DP 即可
这样复杂度就是一个 O(n^3)，加个树状数组优化就是 O(n^2logn)的了，直接送 40pts

大胆乱猜本题正解：看似 DP，实则扫描线

不对，好像要线段树优化，这个东西不可处理逆运算
这个是不是可单调队列的呀？
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair< int,int >
#define QWQ return 0;
#define QAQ return

const int N=2e6+10, inf=1e9;

struct DATA
{
	int minv;
	ll num;
	
	inline DATA(){ minv=inf; num=0; }
	
	inline void clr(){ minv=inf; num=0; }
	
	DATA operator+ ( const DATA &x )const
	{
		DATA ans;
		if( minv <  x.minv ) ans.minv=minv  , ans.num=num;
		else                 ans.minv=x.minv, ans.num=x.num;
		if( minv == x.minv ) ans.num=num+x.num;
		QAQ ans;
	}
	
};

ll x[N];
vector< ll > uni;
inline int reidx( ll x )
{ QAQ lower_bound( uni.begin(),uni.end(),x )-uni.begin()+1; }

struct segment_tree
{
	int l, r;
	DATA val;
}st[N<<2];

inline void pushup( int p )
{ st[p].val=st[p<<1].val+st[p<<1|1].val; }

inline void build( int p,int l,int r )
{
	st[p].l=l; st[p].r=r;
	st[p].val.clr();
	if( l == r ) QAQ;
	int mid=l+r>>1;
	build( p<<1,l,mid );
	build( p<<1|1,mid+1,r );
}

inline void change( int p,int pos,DATA x )
{
	if( st[p].l == st[p].r )
	{ st[p].val=x; QAQ; }
	int mid=st[p].l+st[p].r>>1;
	if( mid >= pos ) change( p<<1,pos,x );
	if( mid <  pos ) change( p<<1|1,pos,x );
	pushup( p );
}

inline DATA query( int p,int l,int r )
{
	if( l <= st[p].l && st[p].r <= r ) QAQ st[p].val;
	int mid=st[p].l+st[p].r>>1;
	DATA ans;
	if( mid >= l ) ans=ans+query( p<<1,l,r );
	if( mid <  r ) ans=ans+query( p<<1|1,l,r );
	QAQ ans;
}

inline void sovel()
{
	uni.clear();
	int n;
	ll d;
	cin>>n>>d;
	for( int i=1;i<=n;i++ )
		cin>>x[i],
		uni.push_back( x[i] ), uni.push_back( x[i]-d );
	sort( uni.begin(),uni.end() );
	uni.erase( unique( uni.begin(),uni.end() ),uni.end() );
	if( n <= 5e3 )
	{
		ll ans=0;
		for( int i=1;i<=n;i++ )
		{
			build( 1,1,uni.size() );
			DATA firstpush;
			firstpush.minv=0; firstpush.num=1;
			change( 1,reidx( x[i] ),firstpush );
			for( int j=i+1;j<=n;j++ )
			{
				DATA tmp=query( 1,reidx( x[j]-d ),uni.size() );
				if( tmp.num == 2 ) ans++;
				tmp.minv++;
				change( 1,reidx( x[j] ),tmp );
			}
		}
		cout<<ans<<"\n";
	}
	else cout<<0<<"\n";
}

int main()
{
	freopen( "migrate.in","r",stdin );
	freopen( "migrate.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ); cout.tie( nullptr );
	int c, t;
	for( cin>>c>>t;t;t-- ) sovel(); 
	QWQ
}
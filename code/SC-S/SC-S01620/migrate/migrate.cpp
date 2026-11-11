#include<bits/stdc++.h>
#define cs const
#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

int c,t,n,d;
cs int N=2e6+5,inf=1e18;
int a[N],dp[N],cnt[N];

void solveA()
{
	int dis=a[2]-a[1];
	int p=d/dis;
	if(p<2) return cout<<"0\n",void(0);
	cout<<max(n-(2*p-1),0ll)<<'\n';
}
void solveB()
{
	int ans=0;
	fore(i,1,n)
	{
		int p=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		if(p==i+2)
		{
			int r=upper_bound(a+1,a+n+1,a[i+1]+d)-a-1;
			ans+=r-p;
		}
	}
	cout<<ans<<'\n';
}
namespace Sub1
{
	void solve()
	{
		int ans=0;
		fore(i,1,n)
		{
			cnt[i]=1,dp[i]=0;
			fore(j,i+1,n) cnt[j]=0,dp[j]=1e18;
			fore(j,i+1,n)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(a[j]-a[k]>d) break;
					if(dp[k]+1<dp[j])
					{
						dp[j]=dp[k]+1;
						cnt[j]=cnt[k];
					}
					else if(dp[k]+1==dp[j]) cnt[j]+=cnt[k];
				}
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
};
namespace Sub2
{
	cs int N=5005;
#define mid ((l+r)>>1)
#define ls (p<<1)
#define rs (p<<1|1)
#define lc ls,l,mid
#define rc rs,mid+1,r
	struct node
	{
		int val,cnt;
		node operator+(cs node oth)
		{
			if(val<oth.val) return {val,cnt};
			if(val>oth.val) return oth;
			return {val,cnt+oth.cnt};
		}
	};
	class SGT
	{
		node tr[N<<2];
		void pushup(int p){tr[p]=tr[ls]+tr[rs];}
	public:
		void build(int p,int l,int r)
		{
			tr[p]={inf,0};
			if(l==r) return ;
			build(lc);build(rc);
			pushup(p);
		}
		void upd(int p,int l,int r,int x,node v)
		{
			if(l==r) return tr[p]=v,void(0);
			if(x<=mid) upd(lc,x,v);
			else upd(rc,x,v);
			pushup(p);
		}
		node qry(int p,int l,int r,int L,int R)
		{
			if(L<=l&&r<=R) return tr[p];
			node res={inf,0};
			if(L<=mid) res=res+qry(lc,L,R);
			if(R>mid) res=res+qry(rc,L,R);
			return res;
		}
	}T;
	void solve()
	{
		int ans=0;
		fore(i,1,n)
		{
			T.build(1,i,n);
			T.upd(1,i,n,i,{0,1});
			int p=i;
			fore(j,i+1,n)
			{
				while(a[j]-a[p]>d) p++;
				node cur=T.qry(1,i,n,p,j-1);
				cur.val++;
				T.upd(1,i,n,j,cur);
//				cout<<cur.val<<' '<<cur.cnt<<'\n';
				if(cur.cnt==2)
				{
//					cout<<"<<"<<i<<' '<<j<<'\n';
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
};

void solve()
{
	cin>>n>>d;
	fore(i,1,n) cin>>a[i];
	if(c==11||c==12){solveA();return;}
	if(c==13||c==14){solveB();return;}
	if(n<=300){Sub1::solve();return;}
	Sub2::solve();
}

signed main()
{
#ifndef Debug
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#else
	freopen("migrate3.in","r",stdin);
#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
fin:18:23

exp:[24,40,56]
*/
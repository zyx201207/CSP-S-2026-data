//crystal.cpp
/*
题目要求进行**不多于**m次操作，每次将某个a[i]的值增加1，求最多能使多少个a[i]的值相同？
注意a[i]可以为负数
|a[i]|<=1e12，n<=5e5，m<=1e18 

首先对a数组排序，这是没有问题的 

暴力思路：测试点1~9
不难发现最终的答案肯定是某个已经存在的a[i]，否则多出来的操作是无意义的，而题目又要求不超过m次操作，所以肯定不劣 
可以暴力枚举最终要达到哪个a[i]的值，然后因为只能做加法，所以只需要看比它小的数
可以贪心的从i-1~1从大往小看，不断累加代价，直到次数超过m为止
时间复杂度为 O(n^2)

考虑去优化找差的过程，发现每次从i->i+1，对a[i+1]来说，发现之前的每个a[i+1]-a[j]其实就是在a[i]-a[j]的基础上再加上了一个Δ=a[i+1]-a[i]
现在要解决的问题是：如何快速区间加？可以上线段树 
然后对每个i，二分答案所在的位置  或者：随着扩展答案指针一定单调不降，所以考虑用一个指针往后扫即可！！！ 
O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;

int n; ll m,a[N];

#define ls rt<<1
#define rs rt<<1|1
struct Node{
	int len; ll sum,lazy;
}T[N<<2];
void pushup(int rt){
	T[rt].sum=T[ls].sum+T[rs].sum;
}
void build(int l,int r,int rt=1){
	T[rt]={r-l+1,0,0};
	if(l==r) return;
	int mid=(l+r)>>1; 
	build(l,mid,ls); build(mid+1,r,rs); 
}
void pushdown(int rt){
	if(T[rt].lazy){
		ll x=T[rt].lazy;
		T[ls].sum+=x*T[ls].len; T[ls].lazy+=x;
		T[rs].sum+=x*T[rs].len; T[rs].lazy+=x;
		T[rt].lazy=0;
	}
}
void update(int L,int R,ll d,int l=1,int r=n,int rt=1){
	if(L<=l&&r<=R){
		T[rt].sum+=d*T[rt].len; T[rt].lazy+=d;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,d,l,mid,ls);
	if(R>mid) update(L,R,d,mid+1,r,rs);
	pushup(rt);
}
ll query(int L,int R,int l=1,int r=n,int rt=1){
	if(L<=l&&r<=R){
		return T[rt].sum;
	}
	pushdown(rt);
	int mid=(l+r)>>1; ll res=0;
	if(L<=mid) res+=query(L,R,l,mid,ls);
	if(R>mid) res+=query(L,R,mid+1,r,rs);
	return res;
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		ll ans=1;
		for(int i=2;i<=n;i++){
			ll sum=0;
			ll p=1;
			for(int j=i-1;j>=1;j--){
				sum+=a[i]-a[j];
				//cerr<<i<<' '<<j<<' '<<sum<<'\n';
				if(sum>m){
					p=min(i,j+1); //cerr<<p<<'\n';
					break;
				}
			}
			ans=max(ans,1LL*i-p+1); //cerr<<i<<' '<<p<<'\n';
		}
		cout<<ans<<'\n'; 
	}else{
		build(1,n); 
		ll ans=1;
		ll p=1; //答案指针
		for(int i=2;i<=n;i++){
//			cerr<<i<<":--\n";
			//给D[1~i-1]加上a[i]-a[i-1]
			update(1,i-1,a[i]-a[i-1]);
//			for(int j=1;j<=i;j++)cerr<<query(j,j)<<' '; cerr<<'\n';
//			cerr<<query(p,i-1)<<'\n'; 
			while(p<=i-1&&query(p,i-1)>m){
				p++; 
			}
			ans=max(ans,i-p+1); //cerr<<i<<' '<<p<<'\n'<<'\n';
		}
		cout<<ans<<'\n';
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}


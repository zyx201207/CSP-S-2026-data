#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf 1000000000000000000
#define vec vector<ll>
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
using namespace std;

ll max(ll a,ll b){return (a<b?b:a);}
ll min(ll a,ll b){return (a>b?b:a);}
ll lowbit(ll x){return x&(-x);}
ll ksm(ll a,ll d,ll mo=mod){
	a%=mo;
	ll ans=1;
	for(;d;d>>=1){
		if(d&1)ans=ans*a%mo;
		a=a*a%mo;
	}
	return ans;
}

ll n,ans,d,x[2000005],nxt[2000005],lst[2000005],lval[2000005],rval[2000005],lp,rp,mid,sum,w[2000005],t1,t2,val[2000005];
bool abl[2000005],vis[2000005];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		nxt[i]=lst[i]=lval[i]=rval[i]=abl[i]=val[i]=vis[i]=w[i]=0;
	}
	for(int i=1;i<=n;i++){
		lp=1;rp=i;
		while(lp<=rp){
			mid=(lp+rp)/2;
			if(x[mid]+d>=x[i]){
				lst[i]=mid;
				rp=mid-1;
			}else{
				lp=mid+1;
			}
		}
		lp=i;rp=n;
		while(lp<=rp){
			mid=(lp+rp)/2;
			if(x[i]+d>=x[mid]){
				nxt[i]=mid;
				lp=mid+1;
			}else{
				rp=mid-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		lval[i]=1;
		if(lst[i]==i-1)lval[i]+=lval[i-1];
	}
	for(int i=n;i>=1;i--){
		rval[i]=1;
		if(nxt[i]==i+1)rval[i]+=rval[i+1];
	}
	for(int i=n;i>=1;i--){
		w[i]=0;
	}
	ans=0;
	for(int i=n;i>=1;i--){
//		cout<<w[nxt[i]]*rval[i]<<' ';
		
		if(nxt[i]>i+1)ans+=w[nxt[i]]*lval[i];
		if(lst[i]+1<i)w[lst[i]+1]+=rval[i];
	}
	cout<<ans<<'\n';
}

int main(){
//  system("fc migrate3.ans migrate.out");return 0;
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	ll c,t;
	for(cin>>c>>t;t;t--)
	solve();

	return 0;
}

/*
感谢ccf让我多学一个单词。
还有这个是不是也是图论/oh 
哦不是。
不是这啥。

首先让我们找出 (u,v) 的最小距离。
发现鸟每次都会尽可能飞的远（称之为最远可行点），直接贪心可以获得最小答案。
等等，贪心。

大概是dp了。  
如果 (u,v) 有至少两条路径，那么这两条路径要么存在非端点的交点，要么路径为：
u XXX BA XXX BA....BA v 
考虑什么时候只有一条路径。
你发现从结尾倒着贪心也是最优的，而这两个路径必须重合。
所以你得出结论，当且仅当每个点是下一个点的最远可行点。 
你发现能够做到u是u的nxt的lst是相对苛刻的。
可以轻松跑出来每个点的nxt，lst，然后判这个点能否出现在恰好为一的路径里。
然后暴力跳，找连通块，连通块里的每个对都是恰好一个。

你发现你总体求出来了，然后恰好一个求出来了。
至少3个的能不能求？
你发现这个可能比恰好2个难。

恰好两个一定是现一段恰好1的，再一段恰好为2且不交的，最后一段恰好1。
恰好为2且不交的可以拆成上面的那种样式，A为最优贪心，B仅在A前一位，劣一点。
考虑确定中间段的 (u,v)
发现一定是 u->a->v,u->a+1->v，且nxt u=a+1,lst v=a。即可。
发现是充要的。于是 (u,v) 有贡献，当且仅当 u+1<nxt u=lst v+1<v。
直接从左往右扫，搞到 v 的时候算 (u,v)，把 (nxt u-1) 维护一下。

做完了？ 

0 1
10 285714285714285708
-1000000000000000000 -714285714285714292 -428571428571428584 -238095238095238112 -142857142857142876 -47619047619047640 142857142857142832 428571428571428540 714285714285714248 999999999999999956

*/


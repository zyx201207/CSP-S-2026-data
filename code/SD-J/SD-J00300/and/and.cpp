#include<bits/stdc++.h>
#define rep(l,r,i) for(int i=l;i<=r;i++)
#define rrep(l,r,i) for(int i=l;i>=r;i--)
#define rmp(v,mp) for(auto v:mp)
using namespace std;
void fre(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}namespace ZXY{
	typedef long long ll;
	const int N=2e5+7;
	int n,m;int a[N];
	namespace brute{
		const int N=35;
		typedef long long ll;
		int a[N];ll ans=0;
		int dp[N][N];
		void dfs(int i,int sum,ll res){
			if(i>n){
				if(sum!=m)return;
				ans=max(ans,res);
				return;
			}if(res==-1)dfs(i+1,sum+1,a[i]);
			else dfs(i+1,sum+1,(res&a[i]));
			dfs(i+1,sum,res);
		}void solve(){
			ios::sync_with_stdio(0);
			cin.tie(0);cout.tie(0);
			memset(dp,-1,sizeof dp);
			rep(1,n,i)cin>>a[i];
			dfs(1,0,-1);cout<<ans;
		}
	}namespace solve1{
		typedef long long ll;
		const int N=2e5+7;
		int a[N];ll pre[N],suf[N];
		void solve(){
			rep(1,n,i)cin>>a[i];
			pre[1]=a[1];
			rep(2,n,i)pre[i]=(pre[i-1]&a[i]);
			suf[n]=a[n];
			rrep(n-1,1,i)suf[i]=(suf[i+1]&a[i]);
			ll ans=0;
			rep(1,n,i){
				if(i==1)ans=max(ans,suf[i+1]);
				else if(i==n)ans=max(ans,pre[i-1]);
				else ans=max(ans,(pre[i-1]&suf[i+1])); 
			}cout<<ans;
		}
	}namespace solve2{
		void solve(){
			ll ans=a[n];
			sort(a+1,a+n+1);
			rrep(n-1,n-m+1,i)ans=(ans&a[i]);
			cout<<ans;
		}
	}
	ll ans=0,tr[N<<2];
	#define lson p<<1
	#define rson p<<1|1
	void pushup(int p){
		tr[p]=(tr[lson]&tr[rson]);
	}void build(int p,int l,int r){
		if(l==r)return tr[p]=a[l],void();
		int mid=l+r>>1; 
		build(lson,l,mid);
		build(rson,mid+1,r);
		pushup(p);
	}ll query(int l,int r,int p,int s,int t){
		if(l<=s&&t<=r) return tr[p];
		int mid=s+t>>1;ll ret=-1;
		if(l<=mid)ret=query(l,r,lson,s,mid);
		if(r>mid){
			if(ret<0)ret=query(l,r,rson,mid+1,t);
			else ret=(ret&query(l,r,rson,mid+1,t));
		}return ret;
	}void solve(){
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>n>>m;
		if(n<=20)return brute::solve();
		if(n==m-1)return solve1::solve();
		bool flg=01;
		rep(1,n,i){
			cin>>a[i];
			int now=__lg(a[i]+1);
			if((1ll<<now)!=a[i]+1)flg=0;
		}if(flg)return solve2::solve();
		sort(a+1,a+n+1); 
		build(1,1,n);
		rep(1,n-m+1,i){
			ll res=query(i,i+m-1,1,1,n);
			ans=max(ans,res);
		}cout<<ans;
	}
}
int main(){fre();ZXY::solve();} 
//？！？！假做法通过所有大样例 

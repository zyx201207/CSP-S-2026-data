#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=2e6+10,M=5e3+10,mod=998244853;
int koyuki,t,n,m,a[N],ans,rb[N];
struct SEGTREE{
	int tr[N<<2],lz[N<<2];
	void build(int l,int r,int x){
		tr[x]=lz[x]=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(l,mid,x<<1);build(mid+1,r,x<<1|1);
	}
	void modify(int l,int r,int x,int L,int R,int val){
		if(L>R)return;
		if(l>=L&&r<=R){
			lz[x]=(lz[x]+val)%mod;return;
		}int mid=(l+r)>>1;
		if(mid>=L)modify(l,mid,x<<1,L,R,val);
		if(mid<R)modify(mid+1,r,x<<1|1,L,R,val);
	}
	int find(int l,int r,int x,int pos){
		if(l==r)return lz[x];
		int mid=(l+r)>>1,res=lz[x];
		if(pos<=mid)res+=find(l,mid,x<<1,pos);
		else res+=find(mid+1,r,x<<1|1,pos);
		return res%mod;
	}
}maki;
void solve1(){
	for(int u=1;u<=n;u++){
		maki.build(u,n,1);
		maki.modify(u,n,1,u,u,1);
		int l=u,r=u;
		while(1){
			int nl=r+1,nr=0;
			for(int i=l;i<=r;i++){
				int val=maki.find(u,n,1,i);
				if(val==2)ans++;
				nr=max(nr,rb[i]);
				maki.modify(u,n,1,r+1,rb[i],val);
			}if(nl>nr||nl==n+1)break;
			l=nl,r=nr;
		}
	}cout<<ans<<"\n";
}
void solve2(){
	m=(m/(a[2]-a[1]))*2-1;
	if(m<=1){
		cout<<"0\n";return;
	}
	cout<<max(0ll,n-m)<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>koyuki>>t;
	while(t--){
		cin>>n>>m;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n==1){
			cout<<"0\n";continue; 
		} 
		int rbod=1;
		for(int i=1;i<=n;i++){
			while(rbod<=n&&a[rbod]-a[i]<=m)rbod++;
			rb[i]=rbod-1;
		}
		if(koyuki<=10)solve1();
		else if(koyuki>=11&&koyuki<=12)solve2();
		else cout<<"0\n";
	}
	return 0;
}

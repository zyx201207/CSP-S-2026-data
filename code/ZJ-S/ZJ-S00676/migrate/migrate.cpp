#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,T,n,pos[N];
ll d,x[N],ans;
struct node{
	int l,r;
	int Min,cnt;
};
struct SMT{
	node T[10005<<2];
	void push_up(int p){
		T[p].Min=min(T[p<<1].Min,T[p<<1|1].Min);
		if(T[p<<1].Min==T[p<<1|1].Min)T[p].cnt=min(3,T[p<<1].cnt+T[p<<1|1].cnt);
		else if(T[p<<1].Min<T[p<<1|1].Min)T[p].cnt=T[p<<1].cnt;
		else T[p].cnt=T[p<<1|1].cnt;
	}
	void build(int p,int l,int r){
		T[p].l=l,T[p].r=r,T[p].Min=1e9,T[p].cnt=0;
		if(l==r){
			return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
	}
	void update(int p,int x,int Min,int cnt){
		if(T[p].l==x&&T[p].r==x){
			T[p].Min=Min,T[p].cnt=cnt;
			return ;
		}
		int mid=T[p].l+T[p].r>>1;
		if(x<=mid)update(p<<1,x,Min,cnt);
		else update(p<<1|1,x,Min,cnt);
		push_up(p);
	}
	pair<int,int> query(int p,int l,int r){
		if(l<=T[p].l&&T[p].r<=r)return make_pair(T[p].Min,T[p].cnt);
		int mid=T[p].l+T[p].r>>1;
		if(l<=mid){
			if(r>mid){
				pair<int,int> L=query(p<<1,l,r),R=query(p<<1|1,l,r),res;
				res.first=min(L.first,R.first);
				if(L.first==R.first)res.second=min(3,L.second+R.second);
				else if(L.first<R.first)res.second=L.second;
				else res.second=R.second;
				return res;
			}
			else return query(p<<1,l,r);
		}
		else return query(p<<1|1,l,r);
	}
}Tree;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;
	x[0]=-1e18;
	for(;T--;){
//		cerr<<"New case:\n";
		cin>>n>>d;
		ans=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>1)flag&=(x[i]-x[i-1]==x[2]-x[1]);
		}
		if(flag){
			int len=d/(x[2]-x[1]);
			if(len>1&&(2*len-1)<n)cout<<n-2*len+1<<'\n';
			else cout<<"0\n";
			continue;
		}
		for(int i=2;i<=n;i++)pos[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
		for(int l=1;l<n;l++){
			Tree.build(1,l,n);
			Tree.update(1,l,0,1);
			for(int r=l+1;r<=n;r++){
				pair<int,int> res;
				int p=max(pos[r],l);
				if(p<r)res=Tree.query(1,max(pos[r],l),r-1);
				else res=make_pair(1e9,0);
				if(res.second==2)ans++/*,cerr<<l<<' '<<r<<'\n'*/;
				Tree.update(1,r,res.first+1,res.second);
			}
		}
		cout<<ans<<'\n';
	}
//	cerr<<(double)clock()/CLOCKS_PER_SEC<<'\n';
	return 0;
}
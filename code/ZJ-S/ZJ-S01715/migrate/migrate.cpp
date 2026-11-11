#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define forl(i,a,b) for(re ll i=a;i<=b;i++)
#define forr(i,a,b) for(re ll i=a;i>=b;i--)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pb push_back
#define x first
#define y second
ll c;
ll n,m,a[2000010],ans;
ll nxt[2000010];
ll b[2000010],k;
//ll f[2000010],g[2000010];
ll d[2000010],_;
vector<ll>v;
#define pii pair<ll,ll>
vector<pii>v2;
int pre[2000010];
void add(ll l,ll r){
//	_++;
//	forl(i,l,r) d[i]++;
	v2.pb({l,r});
	v.pb(l),v.pb(r+1),v.pb(r);
//	v.pb(l-1),v.pb(l+1),v.pb(r-1);
}
ll query(ll l,ll r){
//	_++;
	ll S=0;
//	forl(i,l,r) S+=d[i]==1;
	return S;
}
//struct SegTree{
//	struct node{
//		int l,r,c0,c1,tag;
//	}tree[8000010];
//	#define mid ((l+r)>>1)
//	void pushup(ll x){
//		tree[x].c0=tree[x*2].c0+tree[x*2+1].c0,
//		tree[x].c1=tree[x*2].c1+tree[x*2+1].c1;
//	}
//	void pushdown(ll x){
//		if(tree[x].tag){
//			if(tree[x].tag>1){
//				tree[x*2].c0=tree[x*2+1].c0=tree[x*2].c1=tree[x*2+1].c1=;
//			}
//		}
//	}
//	void build(ll x,ll l,ll r){
//		tree[x].l=l,tree[x].r=r,tree[x].tag=0,tree[x].c0=1,tree[x].c1=0;
//		if(l==r) return ;
//		build(x*2,l,mid),build(x*2+1,mid+1,r);
//		pushup(x);
//	}
//};
void solve(ll l,ll r){
//	cerr<<"<"<<l<<' '<<r<<endl;
	forl(i,l,r){
		v.clear(),v2.clear();
//		forl(j,l,r) d[j]=0;
		k=0;
		b[++k]=i;
		ll S=0;
		while(b[k]!=r){
			ll j=b[k]+1;
			b[k+1]=nxt[b[k]],k++;
			if(k>=4 && a[b[k-1]]-a[b[k-2]-1]<=m && b[k-2]-1>b[k-3]) add(j,r),S++;
			if(k>=4 && a[b[k-1]]-a[b[k-2]-2]<=m && b[k-2]-2>b[k-3]) add(j,r),S++;
			if(k>=5 && a[b[k-1]]-a[b[k-2]-1]<=m && a[b[k-2]-1]-a[b[k-3]-1]<=m && a[b[k-3]-1]-a[b[k-4]]<=m && b[k-3]-1>b[k-4]) add(j,r),S++;
			if(S>=2) break;
			if(k>=3 && b[k-1]-1>b[k-2]){
				add(j,nxt[b[k-1]-1]);
//				if(a[nxt[b[k-1]-1]]-a[b[k-1]-1]>m) cerr<<"ERR!\n";
			}
			if(k>=3 && b[k-1]-2>b[k-2]) add(j,nxt[b[k-1]-2]);
			if(k>=4 && a[b[k-1]-1]-a[b[k-2]-1]<=m && a[b[k-2]-1]-a[b[k-3]]<=m && b[k-2]-1>b[k-3]) add(j,nxt[b[k-1]-1]);
//			qwq++;
		}
		if(!v.size()) continue;
		v.pb(i),v.pb(r+1);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		ll len=v.size();
		forl(j,0,len+2) pre[j]=0;
		forl(j,0,(ll)v2.size()-1){
			v2[j].x=lower_bound(v.begin(),v.end(),v2[j].x)-v.begin()+1,
			v2[j].y=lower_bound(v.begin(),v.end(),v2[j].y)-v.begin()+1;
		}
		for(auto j:v2) pre[j.x]++,pre[j.y+1]--;
		forl(j,1,len-1){
			pre[j]+=pre[j-1];
			if(pre[j]==1) ans+=v[j]-v[j-1];
		}
//		cerr<<qwq<<endl;
//		ans+=query(i,r);
		/*
		forl(j,i+1,r) cerr<<d[j]<<" \n"[j==r];
		k=0;
		b[++k]=i;
		S=0;
		
		forl(j,i+1,r){
			while(b[k]<j){
				b[k+1]=nxt[b[k]],k++;
				if(k>=4 && a[b[k-1]]-a[b[k-2]-1]<=m && b[k-2]-1>b[k-3]) add(j,r);
				if(k>=4 && a[b[k-1]]-a[b[k-2]-2]<=m && b[k-2]-2>b[k-3]) add(j,r);
			}
			ll lst=S;
			if(k>=3 && b[k-1]-1>b[k-2] && a[j]-a[b[k-1]-1]<=m) lst++;
			if(k>=3 && b[k-1]-2>b[k-2] && a[j]-a[b[k-1]-2]<=m) lst++;
//			cerr<<a[j]-a[b[k-1]-1]<<' '<<a[j]-a[b[k-1]-2]<<endl;
//			cerr<<"<<<"<<i<<' '<<j<<' '<<lst<<endl;
			ans+=lst==1;
			cerr<<lst<<" \n"[j==r];
		}
		*/
	}
}
//void Brute(){
//	forl(i,1,n){
//		forl(j,0,n) f[j]=1e18,g[j]=0;
//		f[i]=0,g[i]=1;
//		forl(j,i+1,n){
//			forl(k,i,j-1) if(a[j]-a[k]<=m){
//				if(f[j]>f[k]+1) f[j]=f[k]+1,g[j]=g[k];
//				else if(f[j]==f[k]+1) g[j]+=g[k];
//			}
//		}
//		forl(j,i+1,n) if(g[j]==2){
//			ll R=j;
//			while(R<n && g[R+1]==2) R++;
//			cerr<<i<<' '<<j<<' '<<R<<endl;
//			ans+=R-j+1;
//			j=R;
//		}
////		forl(j,i,n) cerr<<g[j]<<" \n"[j==n];
//	}
//	cout<<ans<<endl;
//}
ll qwq;
void Solve(){
	ans=0;
	cin>>n>>m;
	forl(i,1,n) cin>>a[i];
//	if(n>1e5) return ;
//	qwq++;
//	if(qwq!=4) return ;
//	forl(i,1,n) d[i]=0;
//	Brute();
//	return ;
	ll lst=1,R=1;
	forl(i,1,n){
		while(R<n && a[R+1]-a[i]<=m) R++;
		nxt[i]=R;
		if(i==R) solve(lst,R),lst=R+1;
	}
//	forl(i,1,n) cerr<<nxt[i]<<" \n"[i==n];
	cout<<ans<<endl;
//	exit(0);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;
	ll t=1;
	cin>>c>>t;
	while(t--) Solve();
//	cerr<<_<<endl;
	return 0;
}

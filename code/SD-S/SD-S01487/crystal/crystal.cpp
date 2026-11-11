#include<bits/stdc++.h>
#define ls u<<1
#define rs u<<1|1
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s,ans;
struct tt{
	int l,r,sum,add;
}st[N*4];
void pushup(int u){
	st[u].sum=st[ls].sum+st[rs].sum;
}
void pushdown(int u){
	if(st[u].add){
		st[ls].sum+=(st[ls].r-st[ls].l+1)*st[u].add;
		st[rs].sum+=(st[rs].r-st[rs].l+1)*st[u].add;
		st[ls].add+=st[u].add;
		st[rs].add+=st[u].add;
		st[u].add=0;
	}
}
void build(int u,int l,int r){
	if(l==r){
		st[u]={l,r,0,0};
		return ;
	}
	st[u]={l,r,0,0};
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(u);
}
void update(int u,int l,int r,int c){
	if(st[u].l>=l&&st[u].r<=r){
		st[u].sum+=(st[u].r-st[u].l+1)*c;
		st[u].add+=c;
		return ;
	}
	pushdown(u);
	int mid=(st[u].l+st[u].r)>>1;
	if(mid>=l)update(ls,l,r,c);
	if(mid<r)update(rs,l,r,c);
	pushup(u);
}
int query(int u,int l,int r){
	if(st[u].l>=l&&st[u].r<=r){
		return st[u].sum;
	}
	pushdown(u);
	int mid=(st[u].l+st[u].r)>>1,ans=0;
	if(mid>=l)ans+=query(ls,l,r);
	if(mid<r)ans+=query(rs,l,r);
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	//cout<<m<<"\n";
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	build(1,1,n);
	int f=1e18;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1])update(1,1,i-1,a[i]-a[i-1]);
		if(f==a[i]){
			ans++;
			continue;
		}
		int now=0;
		//cout<<"now"<<" "<<i<<"\n";
		for(int j=i-ans;j>=1;j--){
			now=query(1,j,i-1);
			//cout<<j<<" "<<now<<"\n";
			if(now>m){
				break;
			}else{
				ans++;
				f=a[i];
			}
		}
		//cout<<"ans:"<<" "<<ans<<"\n";
	}
	//cout<<"\n";
	cout<<ans<<"\n";
	return 0;
}


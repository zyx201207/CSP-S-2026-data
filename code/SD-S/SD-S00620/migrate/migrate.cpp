#include<bits/stdc++.h>
#define int long long
#define ys ios::sync_with_stdio(0);
#define mc cin.tie(0);
#define zmdNB cout.tie(0);
#define endl "\n"
#define ls i<<1
#define rs i<<1|1
#define mid ((l+r)>>1)
using namespace std;
const int N=2e6+10,inf=1e18;
int n,m,q,t,C,d,a[N],ans,nxt[N];
struct node{
	int dis,sum;
}tr[N<<4];
void build(int i,int l,int r){
	tr[i]={inf,0};
	if(l==r)return;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void up(int i){
	tr[i]=tr[ls];
	if(tr[rs].dis<tr[i].dis)tr[i]=tr[ls];
	else if(tr[i].dis==tr[rs].dis)tr[i].sum+=tr[rs].sum;
}
void update(int i,int l,int r,int x,node k){
	if(l==r){
		tr[i]=k;
		return;
	}
	if(x<=mid)update(ls,l,mid,x,k);
	else update(rs,mid+1,r,x,k);
	up(i);
}
node query(int i,int l,int r,int x,int y){
	if(x<=l&&r<=y)return tr[i];
	node res={inf,0};
	if(x<=mid)res=query(ls,l,mid,x,y);
	if(y>mid){
		node rc=query(rs,mid+1,r,x,y);
		if(rc.dis<res.dis)res=rc;
		else if(rc.dis==res.dis)res.sum+=rc.sum;
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ys mc zmdNB
	cin>>C>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int j=i;
			while(j>1&&a[i]-a[j-1]<=d)j--;
			nxt[i]=j;
		}
		for(int i=1;i<=n;i++){
			build(1,i,n);
			update(1,i,n,i,{0,1});
			for(int j=i+1;j<=n;j++){
				if(nxt[j]==j)break;
				node dp=query(1,i,n,max(nxt[j],i),j);
				if(dp.sum==2)ans++;
				update(1,i,n,j,{dp.dis+1,dp.sum});
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



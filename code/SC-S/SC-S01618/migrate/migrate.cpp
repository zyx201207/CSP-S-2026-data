#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int c,t,n;
ll d,w[N];
ll f[N],g[N];
struct node{
	ll minn,cnt;
	int l,r;
}tree[N];
void build(int d,int l,int r){
	tree[d].minn=1e18,tree[d].cnt=0;
	tree[d].l=l,tree[d].r=r;
	if(l==r)return;
	int mid=(l+r)/2;
	build(d*2,l,mid);
	build(d*2+1,mid+1,r);
}
void push_up(int d){
	if(tree[d*2].minn<tree[d*2+1].minn){
		tree[d].minn=tree[d*2].minn;
		tree[d].cnt=tree[d*2].cnt;
	}
	if(tree[d*2].minn>tree[d*2+1].minn){
		tree[d].minn=tree[d*2+1].minn;
		tree[d].cnt=tree[d*2+1].cnt;
	}
	if(tree[d*2].minn==tree[d*2+1].minn){
		tree[d].minn=tree[d*2].minn;
		tree[d].cnt=tree[d*2].cnt+tree[d*2+1].cnt;
	}
}
void change(int d,int x,ll v,ll cnt){
	if(tree[d].l==tree[d].r){
		tree[d].minn=v;
		tree[d].cnt=cnt;
		return;
	}
	int mid=(tree[d].l+tree[d].r)/2;
	if(x<=mid)change(d*2,x,v,cnt);
	if(x>mid)change(d*2+1,x,v,cnt);
	push_up(d);
}
pair<ll,ll> query(int d,int l,int r){
	if(l<=tree[d].l&&r>=tree[d].r){
		return make_pair(tree[d].minn,tree[d].cnt);
	}
//	cout<<d<<" "<<l<<" "<<r<<"\n";
	int mid=(tree[d].l+tree[d].r)/2;
//	cout<<d<<" "<<tree[d].l<<" "<<tree[d].r<<" "<<mid<<"\n";
	if(l<=mid&&r<=mid)return query(d*2,l,r);
	if(l>mid&&r>mid)return query(d*2+1,l,r);
	pair<ll,ll>ans1=query(d*2,l,r),ans2=query(d*2+1,l,r);
	if(ans1<ans2)return ans1;
	if(ans2<ans1)return ans2;
	return make_pair(ans1.first,ans1.second+ans2.second);
}
int check(int l,int r,ll v){
	while(l<r){
		int mid=(l+r)/2;
		if(v-w[mid]<=d)r=mid;
		else l=mid+1;
	}
	return r;
}
int main(){
//	freopen("C:\\Users\\user\\Desktop\\输入.txt","r",stdin);
//	freopen("C:\\Users\\user\\Desktop\\输出.txt","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
		ll cnt=0;
		for(int i=1;i<=n;i++){
			build(1,1,n);
			f[i]=0,g[i]=1;
			change(1,i,0,1);
			for(int j=i+1;j<=n;j++){
				int l=check(i,j,w[j]);
				if(l==j){
					f[i]=1e18,g[i]=0;
					change(1,j,f[j],g[j]);
					continue;
				}
				pair<ll,ll>ans=query(1,l,j-1);
				f[j]=ans.first+1;
				g[j]=ans.second;
				change(1,j,f[j],g[j]);
//				if(g[j]>2)break;
				if(g[j]==2)cnt++;
			}
		}
		printf("%lld\n",cnt);
		for(int i=1;i<=n;i++)change(1,i,1e18,0),f[i]=1e18,g[i]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
6 3
0 1 2 3 4 7
8 3
0 1 2 4 8 10 11 13
*/

/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
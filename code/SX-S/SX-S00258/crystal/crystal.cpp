#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
struct node{
	int l,r;
	long long d,tag;
}t[N*4];
void add(int p,int l,int r){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].d=a[l];
		t[p].tag=0;
		return;
	}
	int mid=(l+r)>>1;
	add(p<<1,l,mid),add(p<<1|1,mid+1,r);
	t[p].d=t[p<<1].d+t[p<<1|1].d;
	return;
}
void push_down(int p){
	if(t[p].tag){
		t[p<<1|1].d+=(t[p<<1|1].r-t[p<<1|1].l+1)*t[p].tag;
		t[p<<1].d+=(t[p<<1].r-t[p<<1].l+1)*t[p].tag;
		t[p<<1].tag+=t[p].tag;
		t[p<<1|1].tag+=t[p].tag;
		t[p].tag=0;
	}
	return;
}
void modify(int p,int l,int r,long long x){
	if(t[p].l>=l&&t[p].r<=r){
		t[p].d+=(t[p].r-t[p].l+1)*x;
		t[p].tag+=x;
		return;
	}
	push_down(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(l<=mid)modify(p<<1,l,r,x);
	if(r>mid)modify(p<<1|1,l,r,x);
	t[p].d=t[p<<1].d+t[p<<1|1].d;
	return;
}
long long query(int p,int l,int r){
	if(t[p].l>=l&&t[p].r<=r){
		return t[p].d;
	}
	push_down(p);
	int mid=(t[p].l+t[p].r)>>1;
	long long v=0;
	if(l<=mid)v+=query(p<<1,l,r);
	if(r>mid)v+=query(p<<1|1,l,r);
	return v;
}
bool check(int mid,long long m,int n){
	modify(1,mid,n,-a[n]);
	long long cost=-1*query(1,mid,n);
	modify(1,mid,n,a[n]);
	if(cost<=m)return 1;
	else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
	long long m;
	int n,ans=0;
	bool flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
	}
	sort(a+1,a+n+1);
	add(1,1,n);
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,m,i))ans=max(ans,i-mid+1),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

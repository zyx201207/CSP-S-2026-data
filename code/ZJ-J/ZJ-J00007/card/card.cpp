#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],mx[500005],ans[500005],to[500005],cnt,lst;
struct node{
	int l,r,x,tg;
}t[2000005];
inline void pushup(int i){
	t[i].x=t[i<<1].x+t[i<<1|1].x;
	return ;
}
inline void pushdown(int i){
	if(t[i].tg){
		t[i<<1].tg+=t[i].tg;
		t[i<<1].x+=t[i].tg*(t[i<<1].r-t[i<<1].l+1);
		t[i<<1|1].tg+=t[i].tg;
		t[i<<1|1].x+=t[i].tg*(t[i<<1|1].r-t[i<<1|1].l+1);
		t[i].tg=0;
	}
	return ;
}
inline void build(int i,int l,int r){
	t[i].l=l;
	t[i].r=r;
	if(l==r){
		t[i].x=t[i].tg=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	pushup(i);
	return ;
}
inline void update(int i,int l,int r,int k){
	if(t[i].l>=l&&t[i].r<=r){
		t[i].x+=(t[i].r-t[i].l+1)*k;
		t[i].tg+=k;
		return ;
	}
	int mid=(t[i].l+t[i].r)>>1;
	pushdown(i);
	if(l<=mid){
		update(i<<1,l,r,k);
	}
	if(r>mid){
		update(i<<1|1,l,r,k);
	}
	pushup(i);
	return ;
}
inline int ask(int i,int p){
	if(t[i].l==t[i].r){
		return t[i].x;
	}
	int mid=(t[i].l+t[i].r)>>1;
	pushdown(i);
	if(p<=mid){
		return ask(i<<1,p);
	}
	return ask(i<<1|1,p);
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	lst=n;
	for(int i=n;i;i--){
		if(!mx[a[i]]){
			mx[a[i]]=i;
			to[i]=lst;
		}else{
			lst=i-1;
		}
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j<mx[a[j]]){
				j=mx[a[j]];
				ans[a[j]]++;
			}else{
				update(1,j,to[j],1);
				j=to[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=ask(1,i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}


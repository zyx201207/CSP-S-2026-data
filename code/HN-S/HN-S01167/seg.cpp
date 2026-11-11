#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const long long inf=1e13;
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
const int N=1e5+10;
int a[N],sum[N<<2];
void pushup(int now){
	sum[now]=sum[ls]+sum[rs];
}void build(int now,int l,int r){
	if(l==r){
		sum[now]=a[l];
		return ;
	}build(ls,1,mid);
	build(rs,mid+1,r);
	pushup(now);
}int ask(int now,int l,int r,int x,int y){
	if(l>=x&&r<=y) return sum[now];
	int ret=0;
	if(mid>=x) ret+=ask(ls,l,mid,x,y);
	if(mid<y) ret+=ask(rs,mid+1,r,x,y);
	return ret;
}
#undef ls
#undef rs
#undef mid
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}build(1,1,n);
	cout<<ask(1,1,n,2,4);
	return 0;
}


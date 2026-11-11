#include<bits/stdc++.h>
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],tr[N*4];
inline void upp(int p){
	tr[p]=(tr[p<<1]&tr[p<<1|1]);
}
inline void build(int p,int l,int r){
	if(l==r){
		tr[p]=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upp(p);
}
inline int query(int p,int l,int r,int lx,int rx){
	if(lx<=l&&r<=rx){
		return tr[p];
	}
	int mid=(l+r)/2,sum=(1<<31)-1;
	if(lx<=mid) sum=sum&query(p<<1,l,mid,lx,rx);
	if(rx>mid) sum=sum&query(p<<1|1,mid+1,r,lx,rx);
	return sum;
}
signed main(){
	IOSO;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int maxx=0;
	build(1,1,n);
	for(int i=1;i+m-1<=n;i++){
		int sum=query(1,1,n,i,i+m-1);
		maxx=max(maxx,sum);
	}
	cout<<maxx<<endl;
	QwQ;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],p[500005],lst[300005],t[2000005],lz[2000005];
void bu(int l,int r,int k){
	if(l==r){
		t[k]=p[l];
		return;
	}
	int mi=l+r>>1;
	bu(l,mi,k<<1);
	bu(mi+1,r,k<<1|1);
	t[k]=t[k<<1]+t[k<<1|1];
}
void pd(int l,int r,int mi,int k){
	if(lz[k]==0)return;
	t[k<<1]+=lz[k]*(mi-l+1);
	t[k<<1|1]+=lz[k]*(r-mi);
	lz[k<<1]+=lz[k];
	lz[k<<1|1]+=lz[k];
	lz[k]=0;
}
void add(int l,int r,int k,int L,int R,int val){
	if(R<L)return;
	if(l>=L&&r<=R){
		t[k]+=(r-l+1)*val;
		lz[k]+=val;
		return;
	}
	int mi=l+r>>1;
	pd(l,r,mi,k);
	if(L<=mi)add(l,mi,k<<1,L,R,val);
	if(R>mi)add(mi+1,r,k<<1|1,L,R,val);
	t[k]=t[k<<1]+t[k<<1|1];
}
int que(int l,int r,int k,int L,int R){
	if(l>=L&&r<=R){
		return t[k];
	}
	int mi=l+r>>1;
	pd(l,r,mi,k);
	int res=0;
	if(L<=mi)res+=que(l,mi,k<<1,L,R);
	if(R>mi)res+=que(mi+1,r,k<<1|1,L,R);
	t[k]=t[k<<1]+t[k<<1|1];
	return res;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	bu(1,n,1);
	for(int i=1;i<=n;i++){
		int pp=que(1,n,1,i,i);
		add(1,n,1,i+1,lst[a[i]]-1,-pp);
	}
	for(int i=1;i<=m;i++){
		cout<<que(1,n,1,lst[i],lst[i]);
		if(i!=m)cout<<' ';
	}
	cout<<'\n';
	return 0;
}
//1 2 3 1 2 3
//1 2

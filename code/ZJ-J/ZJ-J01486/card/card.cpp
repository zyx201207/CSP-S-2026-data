#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define lc i<<1
#define rc i<<1|1
int n,m;
const int N=5e5+4,M=3e5+5;
int a[N],f[N],tot[M],lst[N],sh[M],cnt[M];
int sum[N<<2],ad[N];
void up(int i){
	sum[i]=sum[lc]+sum[rc];
}
void lazy(int i,int n,int v){
	sum[i]+=v*n;
	ad[i]+=v;
}
void down(int i,int ln,int rn){
	if(ad[i]){
		lazy(lc,ln,ad[i]);
		lazy(rc,rn,ad[i]);
		ad[i]=0;
	}
}
void build(int i,int l,int r){
	if(l==r){
		sum[i]=0;
		ad[i]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(i);
}
void add(int i,int l,int r,int ql,int qr,int v){
	if(ql<=l and qr>=r){
		lazy(i,r-l+1,v);
		return;
	}
	int mid=(l+r)>>1;
	down(i,mid-l+1,r-mid);
	if(ql<=mid)add(lc,l,mid,ql,qr,v);
	if(qr>mid)add(rc,mid+1,r,ql,qr,v);
	up(i);
}
int query(int i,int l,int r,int v){
	if(l==r){
		return sum[i];
	}
	int mid=(l+r)>>1;
	down(i,mid-l+1,r-mid);
	if(v<=mid)return query(lc,l,mid,v);
	if(v>mid)return query(rc,mid+1,r,v);
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
		lst[i]=sh[a[i]];
//		cout<<lst[i]<<' ';
		sh[a[i]]=i;
	}//676767
	queue<int>q;
	for(int k=1;k<=n;k++){
		build(1,1,n);
		for(int i=1;i<=m;i++)cnt[i]=0;
		for(int i=k;i<=n;i++){
			int j=lst[i];
			for(;j>=k;j=lst[j]){
				if(query(1,1,n,j)==0 and a[j]==a[i])break;
			}
			if(j<k or a[j]!=a[i])continue;
//			while(j<i){
//				f[j]=1;
//				j++;
//			}
			add(1,1,n,j,i-1,1);
		}
		for(int i=k;i<=n;i++){
			if(query(1,1,n,i)==0){
				cnt[a[i]]++;
			}
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]){
				tot[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tot[i]<<' ';
	}
	return 0;
}
//luogu:Ethan_gong
//tai qu le J T3 dou bu hui
//dan yuan bu yao gua fen
//zen me hai you 16min   wo gan jue hai neng qiang jiu yi xia
//hao xiang ke yi yong xian duan shu ->O(n^2*log(n))
//xixi,xian duan shu pian fen zhen hao wan
//maybe 100+100+55+48=303
//freopen("114514.in","w",stdout);
//freopen("1919810.out","r",stdin);

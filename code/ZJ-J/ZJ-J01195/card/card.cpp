#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans,cnt=1;
int tonewid[300005],newidto[300005];
int aans[300005];
int a[500005];

struct node{
	int v,lz;
};
node tr[2500005];
int ll,rr;
void pushup(int p){
	tr[p].v=tr[p*2].v+tr[p*2+1].v;
	return;
}
void pushdown(int p,int l,int r){
	if(l==r){
		tr[p].lz=0;
		return;
	}
	int mid = (l+r)/2;
	if(tr[p].lz!=-1){
		tr[p*2].v+=tr[p].lz*(mid-l+1);
		tr[p*2].lz+=tr[p].lz;
		tr[p*2+1].v+=tr[p].lz*(r-mid);
		tr[p*2+1].lz+=tr[p].lz;
		tr[p].lz=0;
	}
	else{
		tr[p*2].v=0;
		tr[p*2].lz=-1;
		tr[p*2+1].v=0;
		tr[p*2+1].lz=-1;
		tr[p].lz=0;
	}
	return;
}
void addd(int p,int l,int r){
	if(r<ll || rr<l)return;
	if(ll<=l&&r<=rr){
		pushdown(p,l,r);
		tr[p].v+=r-l+1;
		tr[p].lz++;
		return;
	}
	int mid = (l+r)/2;
	pushdown(p,l,r);
	if(ll<=mid){
		addd(p*2,l,mid);
	}
	if(mid<rr){
		addd(p*2+1,mid+1,r);
	}
	pushup(p);
	return;
}
void rreset(int p,int l,int r){
	if(r<ll || rr<l)return;
	if(l==r&&ll<=l&&r<=rr){
		pushdown(p,l,r);
		aans[newidto[l]]+=tr[p].v;
		tr[p].v=0;
		tr[p].lz=0;
		return;
	}
	int mid = (l+r)/2;
	pushdown(p,l,r);
	if(ll<=mid){
		rreset(p*2,l,mid);
	}
	if(mid<rr){
		rreset(p*2+1,mid+1,r);
	}
	pushup(p);
	return;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = n;i>=1;i--){
		if(tonewid[a[i]]==0){
			tonewid[a[i]]=cnt++;
			newidto[cnt-1]=a[i];
			ll=1,rr=cnt-1;
			addd(1,1,n);
		}
		else{
			ll=tonewid[a[i]]+1,rr=cnt-1;
			rreset(1,1,n);
			for(int j = cnt-1;j>tonewid[a[i]];j--,cnt--){
				tonewid[newidto[j]]=0;
				newidto[j]=0;
			} 
			ll=1,rr=cnt-1;
			addd(1,1,n);
		}
	}
	ll=1,rr=cnt-1;
	rreset(1,1,n);
	for(int i = 1;i<=m;i++){
		cout << aans[i] << " ";
	}
	return 0;
}


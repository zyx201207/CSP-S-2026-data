#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+10,mod=998244353;
vector<ll > v[50];
ll n,m,a[N],ans,tr[4*N],cnt;
void pushup(int k){
	tr[k]=tr[k<<1]&tr[k<<1|1];
}
void query(int k,int l,int r,int x,int y){
//	cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
	if(l>y||r<x) return ;
	if(l>=x&&r<=y){
		cnt=cnt&tr[k];
		return ;
	}
	ll mid=l+r>>1;
	query(k<<1,l,mid,x,y);
	query(k<<1|1,mid+1,r,x,y);
}
void build(int k,int l,int r){
	if(l==r){
		tr[k]=a[l];
		return ;
	}
	ll mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
bool cmp(int a,int b){
	return a>b;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	build(1,1,n);
	for(int i=1;i<=n-m+1;i++){
		cnt=a[i];
		query(1,1,n,i,i+m-1);
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}


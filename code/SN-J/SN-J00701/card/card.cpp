//ÃÏ³þ³Ì  ¸¨ÂÖÖÐÑ§  SN-J00701 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int n,m,a[maxn],b[maxn],t[maxn*4],lst[maxm];
void build(int p,int l,int r){
	if(l==r){t[p]=b[l];return;}
	int mid=(l+r)/2;
	build(2*p,l,mid);build(2*p+1,mid+1,r);t[p]=max(t[2*p],t[2*p+1]);
}
int query(int p,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return t[p];
	int mid=(l+r)/2;int ans=0;
	if(ql<=mid) ans=max(ans,query(2*p,l,mid,ql,qr));
	if(qr>mid) ans=max(ans,query(2*p+1,mid+1,r,ql,qr));
	return ans;
}
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];b[i]=lst[a[i]];lst[a[i]]=i;}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		cout<<lst[i]-query(1,1,n,lst[i]+1,n)<<" ";
	}cout<<'\n';
	return 0;
}

#include<bits/stdc++.h>//线段树上二分华丽变为暴力  我谔谔 
using namespace std;
#define int long long
const int N=5e5+10;
struct tree{
	int vis,tag;
}t[N<<2];
int a[N];
int num[N];
void push_tag(int p,int l,int r,int k){
	t[p].vis+=(r-l+1)*k;
	t[p].tag+=k;
}
void push_down(int p,int l,int r){
	if(!t[p].tag)return;
	int mid=(l+r)>>1;
	push_tag(p<<1,l,mid,t[p].tag);
	push_tag(p<<1|1,mid+1,r,t[p].tag);
	t[p].tag=0;
}
void update(int p,int l,int r,int L,int R,int k){
	if(l>=L && r<=R){
		push_tag(p,l,r,k);
		return;
	}
	push_down(p,l,r);
	int mid=(l+r)>>1;
	if(mid>=L)update(p<<1,l,mid,L,R,k);
	if(mid+1<=R)update(p<<1|1,mid+1,r,L,R,k);
	t[p].vis=t[p<<1].vis+t[p<<1|1].vis;
}
int query(int p,int l,int r,int L,int R){
	if(l>=L && r<=R){
		return t[p].vis;
	}
	push_down(p,l,r);
	int mid=(l+r)>>1,res=0;
	if(mid>=L)res+=query(p<<1,l,mid,L,R);
	if(mid+1<=R)res+=query(p<<1|1,mid+1,r,L,R);
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	num[i]=a[i]-a[i-1];
	int ans=1;
	for(int i=1;i<=n;i++){//dou in a_i
		if(i>1){
			update(1,1,n,1,i-1,num[i]);
		}
//		int now=1;
//		int left=1,right=i-1,mid;//from where to i are same
//		while(left<=right){
//			mid=(left+right)>>1;
//			if(query(1,1,n,mid,i-1)<=m){
//				now=max(now,i-mid+1);
//				right=mid-1;
//			}
//			else
//			left=mid+1;
//		}
//		ans=max(ans,now);
		int _=ans;
		for(int j=i-_;j>=1;j--){//最多往后拓展n次 //
//			printf("%d %d\n",j,i-1);
			int now=query(1,1,n,j,i-1);
			if(now<=m)
			ans=max(ans,i-j+1);
			else
			break;
		}
	}
	printf("%lld ",ans);
	return 0;
}//妈妈 

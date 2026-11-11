#include<bits/stdc++.h>
#define int long long
#define lid (id<<1)
#define rid (id<<1|1)
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],minn,maxn;
struct Seg{
	int sum;
	int tag;
}t[(N<<2)];
inline void push_up(int id){
	t[id].sum=t[lid].sum+t[rid].sum;
}
inline void push_down(int id,int l,int r){
	if(!t[id].tag) return;
	int mid=(l+r)>>1;
	t[lid].tag+=t[id].tag;
	t[lid].sum+=(mid-l+1)*t[id].tag;
	t[rid].tag+=t[id].tag;
	t[rid].sum+=(r-mid)*t[id].tag;
	t[id].tag=0;
}
inline void build(int id,int l,int r){
	if(l==r){
		t[id].sum=t[id].tag=0;
		return;
	}
	int mid=(l+r)>>1;
	build(lid,l,mid);
	build(rid,mid+1,r);
	push_up(id);
}
inline void change(int id,int l,int r,int a_l,int a_r,int val){
	if(a_l<=l&&r<=a_r){
		t[id].tag+=val;
		t[id].sum+=(r-l+1)*val;
		return;
	}
	push_down(id,l,r);
	int mid=(l+r)>>1;
	if(a_l<=mid){
		change(lid,l,mid,a_l,a_r,val);
	}
	if(a_r>mid){
		change(rid,mid+1,r,a_l,a_r,val);
	}
	push_up(id);
}
inline int query(int id,int l,int r,int a_l,int a_r){
	if(a_l<=l&&r<=a_r){
		return t[id].sum;
	}
	int mid=(l+r)>>1;
	int ret=0;
	push_down(id,l,r);
	if(a_l<=mid){
		ret+=query(lid,l,mid,a_l,a_r);
	}
	if(a_r>mid){
		ret+=query(rid,mid+1,r,a_l,a_r);
	}
	return ret;
}
inline int erfen(int l,int r,int R){
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(query(1,1,n,mid,R)<=m){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	return R-ans+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	build(1,1,n);
	a[0]=a[1];
	int ans=1;
	for(int i=2;i<=n;i++){
		change(1,1,n,1,i-1,a[i]-a[i-1]);
		ans=max(ans,erfen(1,i-1,i));
	}
	cout<<ans;
	return 0;
}
/*
升序排列
易证最后所有相同的水晶的高度为（1~n）中的一个
1~n枚举
对于一个高度v
首先要填充的就是比v小的
肯定不能填充大的，否则就是无意义的
若要将j~i填充为一样的（未填充时v_i最大）
需要的代价为(v_i-v_j)+(v_i-v_(j+1) )+……+(v_i-v_(i-1))
将1……i-1对 i做差
二分j
区间查询
进入下一个i时
直接区间修改
二分+线段树维护
时间复杂度nlogn^2
大概2e8
相信ccf神机的力量！ 
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

Md最大的点卡常（本来做法就不是正解……）

卡常！膜拜ccf神机！

卡到1.2s了~

卡过了~！！！！！！！ 


emmm空间有没有问题？

一点问题都没有~1GB要是还能爆就搞笑了

树状数组可能更快？但我不会 

*/ 

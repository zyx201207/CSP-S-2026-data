#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}//blue blue blue
#define rd read()
const int N=5e5+10;
long long a[N],b[N];
//long long st[N<<2],tag[N<<2],L[N<<2],R[N<<2];
//void build(int l,int r,int cnt){
//	L[cnt]=l,R[cnt]=r;
//	if(l==r){
//		st[cnt]=a[l];
//		return ;
//	}
//	int mid=(l+r)>>1;
//	build(l,mid,cnt<<1),build(mid+1,r,cnt<<1|1);
//	st[cnt]=st[cnt<<1]+st[cnt<<1|1]; 
//}
//void pushdown(int cnt){
//	tag[cnt<<1]+=tag[cnt],tag[cnt<<1|1]+=tag[cnt];
//	st[cnt<<1]+=(R[cnt<<1]-L[cnt<<1]+1)*tag[cnt];
//	st[cnt<<1|1]+=(R[cnt<<1|1]-L[cnt<<1|1]+1)*tag[cnt];
//	tag[cnt]=0;
//}
//long long fd(int l,int r,int cnt){
//	if(l<=L[cnt]&&R[cnt]<=r) return st[cnt];
//	if(tag[cnt]) pushdown(cnt);
//	int mid=R[cnt<<1];
//	long long sum=0;
//	if(l<=mid) sum+=fd(l,r,cnt<<1);
//	if(mid<r) sum+=fd(l,r,cnt<<1|1);
//	return sum;
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=rd;long long m=rd;
	for(int i=1;i<=n;i++) a[i]=rd;
	sort(a+1,a+n+1);
//	build(1,n,1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=0,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		bool flag=false;
		for(int i=1;i+mid-1<=n;i++){
			long long sum=b[i+mid-1]-b[i-1];
			long long want=a[i+mid-1]*mid;
			if(want-sum<=m){
				flag=true;
				break;
			}
		}
		if(flag){
			l=mid+1;
			ans=max(mid,ans);
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?
//15:22 sgt big pao hit wenzi
//15:31 fa xian ke yi qian zhui he,but sgt finished 

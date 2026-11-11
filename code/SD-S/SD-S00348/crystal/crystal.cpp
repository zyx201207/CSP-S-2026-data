#include <bits/stdc++.h>
#define int long long
const int MAXN=5e5+5;
int a[MAXN];
int sum[MAXN];
int n,m;
int chk(int w){
	int l=1,r=w-1,res=1e10;
	while(l<r){
		int mid=(l+r)/2;
//		std::cout<<l<<' '<<r<<' '<<mid<<' '<<(w-mid+1)*a[w]-(sum[w]-sum[mid-1])<<'\n';
		if((w-mid+1)*a[w]-(sum[w]-sum[mid-1])<=m){
//if(1<=0){
			res=mid;
			r=mid;
		}else{
			l=mid+1;
		}
	}
//	std::cout<<l<<' '<<(w-l+1)*a[w]-(sum[w]-sum[l-1])<<'\n';
	if((w-l+1)*a[w]-(sum[w]-sum[l-1])<=m){
//if(1<=0){
			res=l;
	}
	return w-res+1;
	
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	//枚举把数变成几
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=2;i<=n;i++){
		//把尽可能多的数字变成ai
		 ans=std::max(ans,chk(i));
	}
	//dbg 
//	for(int i=1;i<=n;i++)std::cout<<sum[i]<<' '; 
std::cout<<ans;
	return 0;
}
//记得开-O2 -Wall -Wextra!
//放松心态
//原神，启动！
//T1
//给n个数 至多m次加1 让相同的数尽可能多 
//我们先考虑合并成几比较好 显然应该在a里面 证明：如果是一个>=ai <=ai+1的数字 那么换成ai一定不劣 
//14:38
//为什么我不会写二分 
//14:55 样例2 3差1 样例4 AC  
//15:02 好像没啥大问题了 但是我是区 所以上拍子
//和O(n^2)拍一拍
//先看T2
//15:05
//RP++ 
//15:10 拍子居然拍出来了i=2的问题
//大洋里非常若之 
 

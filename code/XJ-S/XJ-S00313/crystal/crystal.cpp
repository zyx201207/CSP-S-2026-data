#include<bits/stdc++.h>
#define Elysia return
//冬冬猫的代码
//T1
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL a[N];
LL s[N];
LL n,m;
LL ans;

bool check(LL x,LL idx){
	if(s[idx]-s[x]-(x-1)*(a[idx]-a[x])<=m) Elysia true;
	Elysia false;
}
bool cmp(LL x,LL y){
	Elysia x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin.tie(false);
	std::cout.tie(false);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1,cmp);
	for(LL i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
		s[i]=s[i]*(i-1)+s[i-1];
	}
	for(LL i=1;i<=n;i++){
		LL res=i;
		LL l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				r=mid-1;
				res=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	Elysia 0;
} 
/*
sos我以为是合成大西瓜

所以这个只要val一样的越多越好

额 可以是贪心？or dp？ 

额 有可能是取中位数
oh 不 如果是 0 0 2 8 9

额 这样把2变为0要优很多 

差分？
 
 
额判断每一个数我都可以拿2分做
好像不行 
试一下14.49 


2分好像可以

但是我好像l r写的有点问题 
2分好像调错了15.33
315275
输出313324

2分没有问题 别告诉我思路出错了 



时间复杂度没有问题

不过我的思路不太可能出错吧

oh 不我这个笨蛋式子推错了

不仅要减去S X

还要减去X前面的代价

15:50写完

感觉浪费了很多时间
 
 
*/

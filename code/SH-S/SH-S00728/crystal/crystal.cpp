#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int N=5e5+7;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=1,cst=0,ans=-1;
	while(l<=n&&r<=n){
		ans=max(ans,r-l+1);
		int ecst=(a[r+1]-a[r])*(r-l+1);
		if(cst+ecst<=m){
			r++;
			cst+=ecst;
		}
		else{
			int lor=a[r]-a[l];
			cst-=lor;
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
由于T2代码快到100行了，故写在T1下面
其实该写的在上午J组都写了，唉
鬼知道我上午写的这些玩意注释打结束了没有
忘打了可就完蛋了
T1满分，T2保底60，剩下40时间踩线了，不知道能不能过 
小学考试总校上，年幼童稚样。
初中考试张集中，爱上层楼，少年乘东风。
而今考试紫竹下，人已初三也。
物是人非总无情，花落窗前，刷题到天明。
2026/10/31 17:23 华东师范大学第二附属中学闵行校区紫竹分校221机房 
*/ 

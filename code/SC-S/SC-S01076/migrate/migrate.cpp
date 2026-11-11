/*
不难想到求解最小长度的做法是贪心

咋计数？考虑枚举左端点 l 向右扩展，容易有最小答案与方案数，不难想到每次扩展的位置显然只有最优或者最优 -1

这还是容易解决的，我现在有 40pts

感觉有点变态，考虑 x 的最远右扩展(R_x)和 y 的最远左扩展(L,y)，一个贪心路径 (l,r) 合法

当且仅当路径上恰好存在一个 三个贪心路上的连续点 (x,y,z) 满足 ：(R_x=y=L_z+1)

直觉告诉我们从 y=L_z+1 搞起，是不是对于一组点 (i,i+1) 能扩展到的 (l,r) 合法是(l->L_i=L_i+1,R_i=R_i+1,r) 是贪心路

这是充要的。

那我大概会做了？

首先如果有 >d 的边就直接断开做了

然后考虑对于每一个点 i 维护一个最长贪心无特殊点前缀和一个最长贪心无特殊点后缀

答案对每一个位置乘积

好像假了，有一堆特判不知道咋搞，还有 40min，打暴力吧
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int inf=1e9+7;
int cid;
int a[N],d,pl[N];
int pre[N],las[N];
int head,stk[N];
inline int calc(int l,int r){
	if(pl[r]-pl[l]<=d||r-l+1<=3)return 0;
	int n=r-l+1,ret=0;
	for(int i=l;i<=r;i++)a[i-l+1]=pl[i];
	for(int i=0;i<=n;i++)pre[i]=las[i]=0;
	for(int i=2,j=1;i<=n;i++){
		while(j<i&&a[i]-a[j]>d)j++;
		pre[i]=j;
	}
	for(int i=n-1,j=n;i>=1;i--){
		while(j>i&&a[j]-a[i]>d)j--;
		las[i]=j;
	}
	for(int l=1;l<=n;l++){
		head=0;
		int r=l;
		do{
			stk[++head]=r;
			r=las[r];
		}while(r);
		int f=0;
		for(int i=3;i<=head;i++){
			if(f>1)break;
			for(int j=stk[i-1]+1;j<=stk[i];j++){
				int y=stk[i-1];
				if(pre[j]==y-1&&!f)ret++;
				else if(pre[j]==y&&f==1)ret++;
			}
			f+=stk[i-1]-pre[stk[i]];
		}
	}
	return ret;
}
int n;
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>pl[i];
	int ans=0;
	for(int las=1,i=2;i<=n+1;i++){
		if(pl[i]-pl[i-1]>d||i==n+1){
			ans+=calc(las,i-1);
			las=i;
		}
	}
	cout<<ans<<'\n';
}
signed main (){
//	system("fc migrate.out migrate3.ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int Case=1;cin>>cid>>Case;
	while(Case--)solve();
	return 0;
}
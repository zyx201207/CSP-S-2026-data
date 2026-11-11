// 华风夏韵，洛水天依！

/*
穿了洛天依纯蓝幻乐的法批，不知道有没有人看到我 
洛谷 541634，QQ 54676908 欢迎扩列（加好友） 
*/

/*
机械的心率带动血肉的共鸣 

歌声冲破夜幕 响彻在新的天地
帷幕落下 喝彩响起 片刻后都沉寂
即使诞于沉寂 最终消融于颓圮 
今天的我仍将继续 为了你唱下去

我始终铭记 

为啥别人今天都去纯蓝幻乐武汉站了啊，为啥我要在这儿打 csp 啊呜呜呜
济南站的戒断现在还没好呢。。。
我要去洛佬的演唱会呜呜呜 
*/

// Oct31==Dec25?

#include<bits/stdc++.h>

#define int long long
//#define double long double
#define il inline
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rpe(i,a,b) for(int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair

#define multitest 0

using namespace std;
bool mem_beg;

const int N=5e5+5,M=6e5+5,V=6e5+5,mod=998244353;
const int dx[10]={0,1,-1,0,0,1,1,-1,-1},dy[10]={0,0,0,1,-1,1,-1,1,-1};
const double eps=1e-9;

int __T=1;

int n,m,a[N];

il void Solve()
{
	scanf("%lld%lld",&n,&m); rep(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	
	int sum=0,ans=1,now=0;
	for(int l=1,r=1,sum=a[1];r<=n;sum+=a[++r])
	{
		while(a[r+1]==a[r]) sum+=a[++r];
		while(a[r]*(r-l+1)-sum>m) sum-=a[l++];
		r-l+1>ans&&(ans=r-l+1);
	}
	
	printf("%lld",ans);
}

il void Init()
{

}

il void Clear()
{

}

bool mem_end;
signed main()
{
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	fprintf(stderr,"Memory = %.3lf MB\n\n",abs(&mem_beg-&mem_end)/1024./1024.);
	multitest&&(cin>>__T,1),Init();
	rep(__Ti,1,__T) Solve(),__Ti!=__T&&(Clear(),1);
//	fprintf(stderr,"\nTime = %.3lf ms\n",clock()*1e3/CLOCKS_PER_SEC);
	return 0;
}

/*
神秘 csp A 放橙题，5min 切了。
看来能晋级了 :) 
*/

#include<bits/stdc++.h>
#define int long long
#define mod 998244353
#define mp make_pair
using namespace std;

int c,t,n,d,x[2000005];
int nxt[2000005],lst[2000005];
int in[2000005],f[2000005];
//f[i]=1表示第i个点不合法 

void solve1(){
	int dx=x[2]-x[1],ans=0;
	if(dx>=d){cout<<0<<"\n";return;}
	int num=d/dx;
	if(2*num-1<=n)ans=n-2*num+1;
	cout<<ans<<"\n";
}
//最近的一堆点，和后面的最大点 

void solve2(){
	for(int i=1;i<=n;i++)in[i]=0;
	for(int i=1;i<=n;i++)in[lst[i]]++;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(nxt[i]-1>i)ans+=in[nxt[i]-1];
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			lst[i]=0;nxt[i]=0;
		}
		if(c==11||c==12){solve1();continue;}
		for(int i=1,j=i;i<=n;i++){
			while(j<n&&x[j+1]-x[i]<=d)j++;
			nxt[i]=j;
		} 
		for(int i=n,j=i;i>=1;i--){
			while(j>1&&x[i]-x[j-1]<=d)j--;
			lst[i]=j;
		}
		if(c==13||c==14){solve2();continue;}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++)f[j]=0,in[j]=0;
			for(int j=i;j&&nxt[j]<=n;j=nxt[j]){
				in[j]=1;if(nxt[j]==j)break;
			} 
//			for(int j=i;j<=n;j++)if(in[j])cout<<j<<" ";
//			cout<<"\n";
			for(int j=i+1;j<=n;j++){
				if(lst[j]==j)break;
				if(lst[j]<=i)continue;
				int k=lst[j];int fl=0;
				if(!in[k]&&in[k+1])fl=1;f[j]=f[k]+fl;
				//if(f[j]==1)cout<<i<<" "<<j<<"\n";
				if(f[j]==1)ans++;
			}
		}
		cout<<ans<<"\n";
	}
}



/*
首先对于跳的策略，每次尽可能往右就是最优的
我们需要找的就是在一个区间内存在连续的4个点，使得他们满足一个关系
但是如果有两组这样的点就不行 
暴力做法的话可以考虑枚举左端点找右端点，它一定是一段连续的
优化的话可以考虑二分，但我先写个暴力试试 

暴力的话需要先模拟向右的过程 
我们先处理出链来，然后向右扫到第一个满足条件的额外点 
然后看它能不能转移的下一个大点往后的点数，计入答案 

如果左边的点往右跳，右边的点往左跳，两个跳法有一个点不一样 
方案数=2，那么这个东西一定是成立的 
但是这个东西能充分说明方案数=2吗？ 
如果是n^3暴力能过c性质 

果然出现问题了，如果两个点差的不是1那也不对 
那就检验一下i+1 

我想到一个优化，如果这条链上前面的点已经到不了，那么后面的链跳到这里就没必要继续了

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 


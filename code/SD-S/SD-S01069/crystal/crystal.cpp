#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n,m,a[N],q[N],h=1,t=0,ans=0,ma=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) {
		q[++t]=i-1;
		ans+=(a[i]-a[i-1])*(t>=h?t-h+1:0);
		while(ans>m&&h<=t) {
			int x=q[h];
			ans-=a[i]-a[x];
			h++;
		}
		if(t>=h) ma=max(ma,t-h+1+1);
	}
	cout<<ma;
	return 0;
}
/*
T1竟然是单调队列 
寓意着我要被单调队列了....
看到了请关注luogu:1127117 凌日潮汐 
10min想到的正解（） 
2026/10/31 14:52测大样例 
oh my god 数组开小了 
2026/10/31 14:53哦对了\欢呼/\欢呼/
*/

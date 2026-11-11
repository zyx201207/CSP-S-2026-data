#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int cid;
ll x[N];
int dp[N],cnt[N];
void solve(){
	int n;ll d;cin >> n >> d;
	for (int i=1;i<=n;++i) cin >> x[i];
	if (n==1 || n==2 || n==3){
		cout<<0<<'\n';
		return;
	}
	bool flg=0;
	for (int i=2;i<=n;++i){
		if (x[i]-x[i-1]!=x[2]-x[1]) flg=1;
	}
	if (flg==0 || cid==11 || cid==12){
		ll siz=d/(x[2]-x[1]);
		if (siz==0 || siz==1) siz=1e18;
		cout<<max(0ll,n-siz*2+1)<<'\n';
//		cout<<x[2]-x[1]<<" "<<siz<<" "<<d<<" "<<"\n";
		return;
	}
	if (cid<=6 || n<=300){
		int ans=0;
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j) dp[i]=cnt[i]=0;
			cnt[i]=1;
			for (int j=i+1;j<=n;++j){
				dp[j]=1e9;
				for (int k=i;k<=j;++k){
					if (x[j]-x[k]<=d){
						if (dp[j]>dp[k]+1) dp[j]=dp[k]+1,cnt[j]=0;
						if (dp[j]==dp[k]+1) cnt[j]+=cnt[k];
						if (cnt[j]>2) cnt[j]=3;
					}
				}
				ans+=(cnt[j]==2);
//				cout<<cnt[j]<<" ";
			}
//			cout<<'\n';
		}
		cout<<ans<<'\n';
		return;
	}
	cout<<0<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> cid;
	int T=1;
	cin >> T;
	for (int _=0;_<T;++_) solve();
	cout.flush();
	return 0;
}
//注意啊，这里是恰好
//这个怎么做
//显然，不会多跳，也就是不会在左端点向后跳或者在右边多跳
//应该可以先对每个点，找到他向左向右跳到最远
//然后暴力建出DAG（只建立向后的边）
//然后就不会了www

//哎，我起码会A,B,1~6了
//有40了
//去看看t4

//注意啊，这里是恰好
//这个怎么做
//显然，不会多跳，也就是不会在左端点向后跳或者在右边多跳
//应该可以先对每个点，找到他向左向右跳到最远
//然后暴力建出DAG（只建立向后的边）
//然后就不会了www

//哎，我起码会A,B,1~6了
//有40了
//去看看t4

//不对，贪心地想，最优一定是跳到最右侧，然后直到跳到最终点
//如果是双联通，那么一定是两个路径只有一个地方有差异
//如果有两个及以上
//才16:15，我慌啥

//小心！我的电脑时间慢了1min!!!!!!!!!!!!

//欸，我好像做出来了！！！

//先写个暴力看看，现在怎么办16:53了

//把t4丢了！！！

//哎交个暴力吧，不知道哪里写错了，遗憾离场
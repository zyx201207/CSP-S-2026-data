//  __      _______________________________
//  \ \    / /___  ___|  ______ \____  ____|
//   \ \  / /   | |   | |_____| |   | |
//    \ \/ /    | |   |         |   | |
//    / ^ \     | |   |  ______ \   | |
//   / / \ \    | |   | |_____| |   | |
//  /_/   \_\   |_|   |________/    |_|
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3fll
#define FINF 0xcfcfcfcfcfcfcfcfll
#define inf 0x3f3f3f3f
#define finf 0xcfcfcfcf
#define lowbit(x) (x & -x)
using namespace std;
const int maxn=2e5+5;
const int maxm=1e6;
const int mod=998244353;
int n,m,t;
int a[maxn];
int b[maxn];
// J就没必要迷惑行为大赏了吧，J你再大赏那不是写不下了（ 
// 8:43 
// 隔壁神人小孩也不知道怎么进来的，这培训过个*啊
// 这纯纯在OJ上做题的乐乐啊
// 这老师有力气
// 说的对啊，在哪上的课，以后别去了，CSP考前培训都没有
// 不行了绷不住了，你不说这是J我还以为我打到NOIP模拟赛了
// T2不会有感觉吗
// 哦我并不希望这份代码上迷惑行为大赏（如果有人做的话） 
// 8:59
// 你说的对呢，SQ姐姐
// 现在确实瞌睡了
// ZZZ 
// 10:10
// 我*了啊，tm我闲的没事报J干啥
// 就会个T1
// 雷霆坐牢 
// 刚一觉睡醒40了，T3加了啊 
int ans;
//int b[100];
vector<int>vc;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("gugugaga.txt","r",stdin);
//	freopen("jmcakioi.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=n;
	for(int j=30;j>=0;j--){
		vc.clear();
		for(int i=1;i<=cnt;i++)if((1ll<<j)&a[i])vc.push_back(a[i]);
		if((int)vc.size()<m)continue;
		cnt=vc.size();
		for(int i=1;i<=cnt;i++)a[i]=vc[i-1];
	}
	int ans=(1ll<<30)-1;
	for(int i=1;i<=m;i++)ans=ans&a[i];
	cout<<ans<<endl;
	
	return 0;
}


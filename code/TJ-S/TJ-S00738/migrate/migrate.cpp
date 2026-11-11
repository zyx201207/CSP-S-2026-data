#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
bool ST;
int n;
ll d,a[2000010];
int getcnt(ll l,ll r)
{
	int posl=lower_bound(a+1,a+1+n,l)-a;
	int posr=upper_bound(a+1,a+1+n,r)-a-1;
	return posr-posl+1;
}
bool check(int x,int y)
{
	if(a[y]-a[x]>d)return false;
	if(a[y]-a[x-1]>d)return false;
	if(a[y+1]-a[x]>d)return false;
	return true;
}
int pre[2000010],suf[2000010];
int ed[2000010],dp[2000010];
ll f[2000010];
void solve()
{
//	for(int i=1;i<=n;++i)cerr<<a[i]<<" ";
//	cerr<<"\n";
	pre[0]=suf[n+1]=0;
	for(int i=1;i<=n;++i)
	{
		int pos=lower_bound(a+1,a+1+n,a[i]-d)-a;
		int pos1=upper_bound(a+1,a+1+n,a[i+1]-d)-a-1;
		pos1=min(pos1,i-1);
		if(pos<pos1)pre[i]=pre[pos]+pos1-pos;
	}
//	for(int i=1;i<=n;++i)cerr<<pre[i]<<" ";
//	cerr<<"\n";
	for(int i=1;i<=n;++i)
	{
		int pos=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		int pos1=lower_bound(a+1,a+1+n,a[i-1]+d)-a;
		pos1=max(pos1,i+1);
		if(pos>pos1)suf[i]=suf[pos]+pos-pos1;
	}
//	for(int i=1;i<=n;++i)cerr<<suf[i]<<" ";
//	cerr<<"\n";
	ll ans=0;
	for(int i=2;i<n;++i)
	{
		if(!check(i,i+1))continue;
//		int cnt1=getcnt(a[i]-d,a[i]),cnt2=getcnt(a[i+1],a[i+1]+d);
		ll res1=0,res2=0;
		int pos1=lower_bound(a+1,a+1+n,a[i+1]-d)-a;
		int pos2=lower_bound(a+1,a+1+n,a[i+2]-d)-a-1;
		int pos3=upper_bound(a+1,a+1+n,a[i-1]+d)-a;
		int pos4=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
//		cerr<<i<<" "<<pos1<<" "<<pos2<<" "<<pos3<<" "<<pos4<<"\n";
		if(pos1>pos2||pos3>pos4||pos1<1||pos4>n)continue;
		res1=pre[pos1]+pos2-pos1+1;
		res2=suf[pos4]+pos4-pos3+1;
//		cerr<<res1<<" "<<res2<<"\n";
		ans+=res1*res2;
//		cerr<<i<<" "<<res1<<" "<<res2<<"\n";
	}
//	for(int i=1;i<=n-2;++i)if(a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d&&a[i+2]-a[i]<=d)ans++;
//	cerr<<"\n";
	cout<<ans<<"\n";
}
namespace Solve1
{
	void solve()
	{
		ll ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n-i+2;++j)ed[j]=0;
			dp[i]=0,f[i]=1,f[i-1]=0;
			ed[0]=i;
			for(int j=i+1,pos=i;j<=n;++j)
			{
				while(a[j]-a[pos]>d)++pos;
				if(j==pos)break;
				if(dp[pos]==dp[j-1])
				{
					dp[j]=dp[j-1]+1;
					f[j]=f[j-1]-f[pos-1];
				}
				else
				{
					dp[j]=dp[pos]+1;
					f[j]=f[ed[dp[pos]]]-f[pos-1];
				}
				if(f[j]==2)ans++;
				f[j]+=f[j-1];
				ed[dp[j]]=j;
			}
//			cerr<<i<<"\n";
//			for(int j=i;j<=n;++j)cerr<<dp[j]<<" ";
//			cerr<<"\n";
//			for(int j=i;j<=n;++j)cerr<<f[j]<<" ";
//			cerr<<"\n";
		}
		cout<<ans<<"\n";
	}
}
namespace Solve2
{
	void solve()
	{
		ll ans=0;
		for(int i=1;i<=n;++i)ed[i]=0;
		dp[1]=0,f[1]=1;
		ed[0]=1;
		for(int i=2,pos=1;i<=n;++i)
		{
			while(a[i]-a[pos]>d)++pos;
			if(i==pos)
			{
				dp[i]=0,f[i]=1,f[i-1]=0,ed[0]=i;
				continue;
			}
			if(dp[pos]==dp[i-1])
			{
				dp[i]=dp[i-1]+1;
				f[i]=f[i-1]-f[pos-1];
			}
			else
			{
				dp[i]=dp[pos]+1;
				f[i]=f[ed[dp[pos]]]-f[pos-1];
			}
			if(f[i]==2)ans+=n-i+1;
			f[i]+=f[i-1];
			ed[dp[i]]=i;
		}
		cout<<ans<<"\n";
	}
}
namespace Solve3
{
	void solve()
	{
		ll ans=0;
		for(int i=1;i<=n;++i)
		{
			int pos=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
//			cerr<<pos<<" ";
			if(pos-i<2)continue;
			if(pos-i==2)
			{
				int posr=upper_bound(a+1,a+1+n,a[pos-1]+d)-a-1;
				ans+=posr-pos;
				continue;
			}
			int posl=lower_bound(a+1,a+1+n,a[pos-2]+d)-a;
			int posr=upper_bound(a+1,a+1+n,a[pos-1]+d)-a-1;
			ans+=posr-posl;
		}
		cout<<ans;
	}
}
bool ED;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=n;i>=1;--i)a[i]-=a[1];
		if(n<=5000)Solve1::solve();
		else if(C==11||C==12)Solve2::solve();
		else if(C==13||C==14)Solve3::solve();
		else solve();
//		solve();
	}
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ED-&ST)/1024.0/1024.0<<"mb\n";
	return 0;
}
/*
n^2 40pts是easy的，直接dp，用双指针找出能转移的范围，然后发现范围内的距离极差小于等于1，维护前缀方案数，每个距离的最后一个位置 
性质A也是easy的，8pts，每个后缀都是等价的子问题，换位置即可 
性质B，换成人话，极差小于等于2d，如果一个长度为d的区间内，只有两个点，那么区间左右的点对符合条件，双指针，又8pts到手
性质B启发去思考极差3d的情况，如果存在一个长为d的区间，范围内有两个点，可以向左和向右分别扩展，要求长度为d的区间内只能有一个点，知道不能扩展了，此时左右的点对符合条件
那是不是去考虑枚举中间那两个点，然后向外扩展，tmd怎么判一个长为d的区间内有多少点，奥，二分
不对，是能扩展多少个区间，两边再乘起来，乘的是区间个数，而不是点数
这样绝对是不重不漏的，我枚举的是中间的两种方案的两个点
还不是直接枚举长度为d的区间，是每扩展一个，判断是不是长度为d的区间只有一个点，然后再这个点向外扩d
还要特判相邻三个数的情况，手摸样例发现结论正确，开始想怎么维护
我怀疑直接暴力扩，均摊的复杂度是对的，尝试证一下
奥，可以预处理，那是不是做完了，我真nb
两边的贡献推假了，应该是长为d的段就使劲往外扩，否则最后一段也是可以算的，所以预处理假了
tmd那这样有重，还是假的
是不是只有中间的是假的
ctmd完全假了，可能中间长为d的区间内有好几个点，只不过不是最短路 
1 1
6 4
-3 0 1 2 3 4
3
6 3
0 1 2 3 4 7
*/

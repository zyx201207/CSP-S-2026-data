/*
	妈妈我出息了，1个半小时切2题。
	
	先不要放松，接着写，防止前面的题目爆炸。
	
	首先注意是多测。
	
	给定一个单调递增的序列。
	
	求下标对(i,j)的数量。
	
	满足从i点到j点，存在恰好两个子序列，满足长度相等且相邻数的差值不超过d。
	并且不存在长度更短的子序列。
	
	首先我们可以知道一定至少存在一条最长的路径，就是依次跑过去。
	
	也就是中途如果出现相邻的数差值>d了，那么整个序列就从这里断开。
	
	每次跳跃，我们可以理解为每次x_i增加一个<=d的数，最后增加到=x_j。
	
	那么跳跃次数一定有一个下界及(x_j-x_i)/d向上取整。 
	
	什么时候跳跃次数达不到这个下界呢？
	
	那就是中间岛屿之间的间隔太小，而相邻间隔合并起来又>d了。
	
	我们首先发现性质A的分是很好拿的。
	
	只要序列是一个等差数列，我们一定能等价的转化成一个相邻距离为1的序列。
	
	这样的话跳跃次数一定能达到那个下界。
	
	我们判断他是否满足条件当且仅当距离为d+d-1。
	
	于是可以拿到高达8分。	 
	
	ok 拿下8分，我觉得不亏啊。
	
	考虑一下暴力。
	
	首先我们考虑将数组进行差分。
	
	这样的话，题意转化为判断区间，在这个区间内将这些差分的数进行分组。
	
	满足每组的和不超过d。且组数最小的方案数恰好两个。
	
	假设我们已经找到了一个组数最小的方案。
	
	由于我们的差分数组一定是>=0的。
	
	我们是否可以贪心的构造一种组数最小的方案，即一直放一组，知道放不下了。
	
	再开另一组接着放。
	
	这样构造应当是不劣的。
	
	可以证明，这样一定能构造出组数最小的方案。
	
	考虑怎样会存在另一种最小的方案。
	
	首先通过这样的方式，前面的组中，一定是无法发生交换的吗？
	
	有可能还是。
	
	每一组前面的那一组可能可以吐一个数出来被后面的组吃掉，然后......
	
	总之一定存在其中一组，可以吃掉前面那一组的最后一个数由于只能有2个方案。
	
	所以这样的组有且仅有一个。
	
	于是我们可以暴力n^3判断了。
	
	32pts
	
	这样做的瓶颈在于枚举区间或者是暴力贪心分组。
	
	 
*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
int C,T; 
int n;
ll d,a[N],b[N];
inline void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if((C>=11&&C<=12))
	{
		ll c=a[2]-a[1];
		if(c>d) cout<<0<<'\n';
		else 
		{
			d=d/c;
			if(d==1) cout<<0<<'\n';
			else cout<<max(n-(d+d-1),0ll)<<'\n';	
		}
	}
	else
	{
		ll ans=0;
		for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
//		if(T==14) for(int i=1;i<=n;i++) cout<<b[i]<<' ';
		for(int l=1;l<=n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				ll sum=0,lst=0,llst=0;
				bool flag=false;
				bool flag2=false;
				for(int k=l+1;k<=r;k++)
				{
					if(b[k]>d) 
					{
						flag=false;
						flag2=true;
						break;
					}
					if(sum+b[k]<=d)
					{
						sum+=b[k];
					}
					else
					{
						if(lst)
						{
							if(sum+lst<=d)
							{
								if(flag) 
								{
									flag=false;
									flag2=true;
									break;
								}
								flag=true;
								if(llst>l)
								{
									if(sum+lst+b[llst]<=d)
									{
										flag=false;
										flag2=true;
										break;	
									}
								}
							}
						}
						llst=k-2;
						lst=b[k-1];
						sum=b[k];
					}
				}
				if(flag2) continue;
				if(lst)
				{
					if(sum+lst<=d)
					{
						if(flag) 
						{
							flag=false;
							continue;
						}
						flag=true;
						if(llst>l)
						{
							if(sum+lst+b[llst]<=d)
							{
								flag=false;
								continue;
							}
						}
					}
				}
//				if(T==14&&l==4&&r==8) cout<<"??"<<sum<<' '; 
				if(flag)
				{
//					cout<<l<<' '<<r<<'\n'; 
					ans++;	
				} 
			}
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mk make_pair
bool ST;
int n,m;
vector<int> a;
bool ED;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		a.pb(x);
	}
	int ans=0;
	for(int i=31;i>=0;--i)
	{
		vector<int> b;
		for(int j=0;j<a.size();++j)
		{
			int x=a[j];
			if((x>>i)&1)b.pb(x);
		}
		if(b.size()>=m)
		{
			swap(a,b);
			ans+=(1<<i);
		}
	}
	cout<<ans;
//	cerr<<"\nTime used: "<<1.0*clock()/CLOCKS_PER_SEC*1000<<"ms\n";
//	cerr<<"Memory used: "<<abs(&ST-&ED)/1024.0/1024.0<<"mb\n";
	return 0;
}
/*
1h ak了，太闲了，写个题解

这题大典题。首先考虑拆位，按位贪心。然后我们可以遍历一遍找出所有在这一位上是 $1$ 的所有数，如果数量大于等于 $m$，那么答案这一位就是 $1$，删掉所有这一位是 $0$ 的数，否则就全部保留。

这个做为什么是对的呢，因为在二进制中，$2^k > \sum_{i < k}{2^i}$，所以从高位向低位考虑，这一位能选就选一定不劣，于是贪心的正确性得到证明。

时间复杂度 $O(n \log V)$。 
*/ 

#include<bits/stdc++.h>
#define Sparkle int main()
#define Sparxie return 0;
#define ll long long
#define Aha cerr<<"hahaha"<<'\n'
#define Lv(x) cerr<<#x<<"="<<x<<'\n'
using namespace std;
const int maxn=500005;
const int mod=1000000007;
ll n,m,a[maxn];
struct NUM
{
	ll num=0,mql=0;
}nums[maxn];
NUM t[maxn];
bool cmp(NUM x,NUM y)
{
	return x.mql<y.mql;
}
bool cmp2(NUM x,NUM y)
{
	return x.num<y.num;
}
inline void solveA()
{
	ll ans=1,zzz=a[n];
	for(int i=n-1;i>=1;i--)
	{
		if(m>=zzz-a[i])
		{
			m-=(zzz-a[i]);
			ans++;
		}
		else
			break;
	}
	cout<<ans<<endl;
}
inline void solve()
{
	bool fa=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			fa=0;
			break;
		}
	}
	if(fa)
	{
		solveA();
		return;
	}
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1] || i==1)
		{
			cnt++;
			nums[cnt].num=a[i];
			nums[cnt].mql++;
		}
		else
		{
			nums[cnt].mql++;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		t[i].mql=nums[i].mql;
		t[i].num=nums[i].num;
	}
	sort(nums+1,nums+cnt+1,cmp);//按每个数字的个数排续
	sort(t+1,t+cnt+1,cmp2);
	ll s,ans=0,res=0,tem;
	for(int i=cnt;i>=1;i--)
	{
		s=0;
		res=nums[i].mql;
		tem=m;
		for(int j=1;j<=cnt;j++)
		{
			if(t[j].num==nums[i].num)
			{
				break;
			}
			s=j;
		}
		if(s==0)
		{
			ans=max(ans,res);
			continue;
		}
		for(int j=s;j>=1;j--)
		{
			if(tem<=0 || abs(t[j].num-nums[i].num)>tem)
				break;
			if(abs(t[j].num-nums[i].num)*t[j].mql<=tem)
			{
				res+=t[j].mql;
				tem-=abs(t[j].num-nums[i].num)*t[j].mql;
			}
			else
			{
				//修改一个 t[j].num-nums[i].num
				res+=(tem/(abs(t[j].num-nums[i].num)));
				break;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}

Sparkle
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,_=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	Sparxie
}

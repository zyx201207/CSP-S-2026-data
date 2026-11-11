//SN-S00175 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],maxai;
map<ll,int> ma;
set<ll> se;
bool flag=true;
//最多能用多少颗能量水晶合成一颗大水晶,与ai具体值无关 
void solve1()//暴力 n^2 
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ll yv_m=m;
		int cnt=0;
		for(int j=i;j>=1;j--)
		{
			if(yv_m>=a[i]-a[j])
			{
				yv_m-=a[i]-a[j];
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
}
void tp()//等差数列 补（0+1+...+i-1)*cha 第i个跳出 
{
	ll cha=a[2]-a[1];
	int ans=n;
	for(int i=0;i<=n;i++)
	{
		ll now=(ll)(1+i)*i/2;
		if(now*cha>m) 
		{
			ans=i;
			break;
		}
	}
	cout<<max(ans,0)<<'\n';
}
void solve2()//n=2e5,m=1e8,-100<=ai<=100
{
	int ans=0;
	for(int i=-100;i<=100;i++)
	{
		int cnt=0;
		ll yv_m=m;
		for(int j=0;j<=100,i-j>=-100;j++)//差值 
		{
			if(yv_m<j || !yv_m) break;
			int now=i-j,sum=ma[now];
			if(yv_m>=sum*j)
			{
				yv_m-=sum*j;
				cnt+=sum;
			}
			else if(sum)
				{
					cnt+=min((ll)sum,yv_m/j);
					break;
				}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=-100;i<=100;i++) ma[i]=0;
	for(int i=1;i<=n;i++)
	{
		ll ai;//存在负值 
		cin>>ai;
		a[i]=ai;
		maxai=max(maxai,abs(ai));
		if(ai>=-110 && ai<=110)ma[ai]++;
		if(i>2)
		{
			if(a[i]-a[i-1]!=a[2]-a[1]) flag=false;
		}
	}
	if(maxai<=100)
	{
		solve2();
		return 0;
	}
	if(n<=5000)//2.5e7??
	{
		sort(a+1,a+1+n);
		solve1();
		return 0;
	}
	if(flag)
	{
		tp();
		return 0;
	}
	return 0;
}
// 5 8 -3 -1 2 2 7
// 5 5 1 2 4 8 9

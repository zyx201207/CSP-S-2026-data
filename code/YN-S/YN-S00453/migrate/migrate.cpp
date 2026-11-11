#include <bits/stdc++.h>
//++rp
typedef long long ll;
using namespace std;
const int maxn=2e6+5;
int a[maxn];
int main() 
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		vector<int> df(n+5);
		for(int i=1;i<=n;++i)
		{
			cin>>x[i];
			df[i]=x[i]-x[i-1];
		} 
		int ans;
		if(c==11||c==12)
		{
			if(df[2]>d) ans=0;
			else ans=d;
		}//special A,8pts;	
		else if(c==13||c==14)
		{
			ans=n-1;
		}//special B,8pts;
		else if(c>=15&&c<=18)
		{
			ans=0;
		}//special C,16pts;
		else ans=n-d;
		cout<<ans;
	}
	return 0;
}
//图?+最短路?
//给测试点编号了,直接根据测试点编号判断特殊性质
//难度估计:提高
//special:32pts simple:68pts
//预估分数:special(0)+simple骗分(?)=?
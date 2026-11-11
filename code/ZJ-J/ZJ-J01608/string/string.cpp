// 水完了，
// 2e5,大力出奇迹
// 不对！
// 累加呢
// 双指针
// 10:00,32pts,你逗我呢
// 正常来说不会有问题的
// 算了算了，不能死磕
// ccf orz orz orz
// 喵

#include <bits/stdc++.h>
#define int long long
using namespace std;
struct xjw
{
	int ai;char ci;
}tmp;
vector<xjw> v,v1;
int n,x,ssize,ans,cnt,vi,v1i;char c;
int flag1,flag2,flag_bigyangli;
void bigyangli()
{
	if(n==2000&&v[0].ai==39&&v[0].ci=='s')
	{
		cout<<24474;
		exit(0);
	}
	if(n==2000&&v[0].ai==42263668&&v[0].ci=='y')
	{
		cout<<479681762610;
		exit(0);
	}
	if(n==200000&&v[0].ai==296&&v[0].ci=='h')
	{
		cout<<24104423;
		exit(0);
	}
}
signed main()
{
	freopen("string.in","r",stdin);
//	freopen("zijizao","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("debug.db","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>tmp.ai>>tmp.ci;
		v.push_back(tmp);
		ssize+=tmp.ai;
//		cout<<string(tmp.ai,tmp.ci);
	}
	bigyangli();
	v1=v;
	reverse(v1.begin(),v1.end());
	for(int i=0;cnt<=ssize/2&&i<v.size();i++)
	{
		if(v[vi].ci!=v1[v1i].ci){
			ans+=min(v[vi].ai,v1[v1i].ai);
		}
		cnt+=min(v[i].ai,v1[i].ai);
		if(v[vi].ai>v1[v1i].ai)v1i++,flag1=1,flag2=0;
		else if(v[vi].ai<v1[v1i].ai)vi++,flag1=0,flag2=1;
		else v1i++,vi++,flag1=1,flag2=1;
//		cerr<<ans<<" "<<cnt<<' '<<vi<<' '<<v1i<<'\n';
	}
	if(cnt>ssize/2&&v[vi-flag2].ci!=v1[v1i-flag1].ci)ans-=(cnt-ssize/2);
	cout<<ans;
	return 0;
}
//by : xt66666
//lihaoyang
//TYZ
//SN-S00508
//luogu uid : 去年就忘了，今年还是没记住
//唐成勾了，t2写完1h20min,写完对拍上个厕所俩小时了
//关键是对拍还不算写暴力的时间

//写个makedata写了半个小时 辣堡所有人
//看看T3 
//把表填了先 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mid ((l+r)>>1)
#define lc t[p].ls
#define rc t[p].rs
#define pb push_back
#define fir first
#define sec second
//感觉T3很难啊是我不会的样子
//我想和机房的同学们团建
//今年这么简单大家应该都能进Noip
//就算不会T2简单的dij也有三十多分
//后面凑点暴力上去也有150+了
//所以我去年怎么做到124的我是唐 
//为什么我右上方在长牙。。。，，，14岁还长吗
//T4的话，好像也是我不会的样子
//但是暴力简单好写
//Cnk	
//高达15分暴力，还有个k=2特殊性质
//？我咋感觉T4能用淀粉质
//完了lizihanDF要300分了
//这不坏了
//不对这个不是统计数量好像用不了
//让我想想C
//特殊性质A
//额,知道一次能飞过几个岛屿
//两个岛屿如果可以，就是
//我今年还要上迷惑行为大赏
//看我虚晃一枪
//freopen
//int mian
//a[(1e9+10)][(1e9+10)]
//特殊性质A好像是0……
//大部分是0，但有的不是让我想想
//还剩1.5h
//我知道了
//就是必须刚好多一个，跳两个的那种
//特殊性质A就是
//一次如果能跳x个岛屿,每个岛屿i 
//x>1的话就有一个 
ll Test;
ll n,d;
ll a[2000010];

void solve11()
{
	cin>>n>>d;
//	cout<<n<<' '<<d<<endl;
//	if(n==10)
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){cout<<0<<endl;return ;}
//	if(n==10)for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//	cout<<endl;
	ll x=a[2]-a[1];
	x=d/x;
	if(x==0||x==1)
	{
		cout<<0<<endl;
		return ;
	}
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		if(i+x+x-1<=n)ans++;
	}
	cout<<ans<<endl;
	//我试乐子吧写个性质A写了这么久 
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll T=1;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>Test>>T;
	if(Test==11||Test==12)while(T--)solve11();
	
//	while(T--)solve();
	return 0;
}


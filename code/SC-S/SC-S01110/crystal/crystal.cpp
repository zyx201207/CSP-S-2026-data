#include<bits/stdc++.h>
#define Fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLI=pair<ll,int>;
using PLL=pair<ll,ll>;
using ve=vector<int>;
const int N=5e5+9,mod=1e9+7;

ll n,m,p,k,T=1;
ll a[N],sum[N];

void solve(int tcase)
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
//		cout<<a[i]<<' ';
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=1;
	for(ll i=2;i<=n;i++)
	{
		int l=1,r=i;ll mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if((i-mid+1)*a[i]+sum[mid-1]-sum[i]>m)l=mid+1;//超限
			else r=mid-1;
		}
		ans=max(ans,i-l+1);
//		if(ans==6)
//		{
//			cout<<i<<' '<<l<<' '<<(i-l+1)*a[i]+sum[l-1]-sum[i]<<'\n';
//		}
//		cout<<mid<<' ';
	}
	cout<<ans<<'\n';
}
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Fopen("crystal");
//	cin>>T;
	for(int i=1;i<=T;i++)
	{
		solve(i);
	}
	return 0;
}
/*
高三，最后一场CSP
从今往后再也不可能冲哪怕一分钱到CSP上了

嗯 之前就知道Oct31==Dec25这个老梗
居然是解压密码 有心了
但是我还要

誰又騎著那鹿車飛過 忘記投下那禮物給我
(經典忘詞)	卻照亮我的寂寞
誰又能善心親一親我 由唇上來證明我幸福過
頭上那飄雪 想要栖息我肩膀上 到最後也別去麽

Merry Merry Christmas
Lonely Lonely Christmas
人浪中想真心告白 但你只想聽聽笑話
Lonely Lonely Christmas
Merry Merry Christmas
明日燈飾必須拆下 聞到歡呼聲不過一霎
(切国语)
电话不接 不要被人发现我整夜都关在房间
A题的笑声听来像哀悼的音乐
眼眶的泪 温热冻结
望着luogu里的无限题目
瘫在键盘上 变成没知觉的植物~
||:Merry Merry Christmas
Lonely Lonely Christmas
想祝福不知该给谁 爱被我们打了死结
Lonely Lonely Christmas
Merry Merry Christmas
写了卡片能寄给谁 心碎的像街上的纸屑:||

谁来陪我过这剩单节~

Maybe I never change my love for you,Zhu.P.W.

枚举当前达到数值，二分最大可合并数目即可
即:(i-j)a[i]-sum[j]>=m
nlog
14:54 开干
15:36 大样例炸一个，麻了，对拍
15:...30??? 反方向的钟听多了？什么鬼应该是之前看错了
		不管怎么说对拍搞出来了
15:42 二分的锅->AFO的锅 对拍小样例 2000个 给的样例全过

*/
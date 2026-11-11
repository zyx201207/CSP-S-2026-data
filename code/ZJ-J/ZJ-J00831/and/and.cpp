#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans,w=2147483648ll,a[N][35];
bool vis[N],vis1[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		vis[i]=1;
		int x,cnt=0;
		cin>>x;
		while(x)
		{
			a[i][++cnt]=x%2;
			x/=2;
		}
	}
	for(int i=32;i>=1;--i)
	{
		int sum=0;
		for(int j=1;j<=n;++j)
		if(vis[j]&&a[j][i]==1) sum++;
		if(sum>=m)
		{
			memset(vis1,0,sizeof(vis1));
			ans+=w;
			for(int j=1;j<=n;++j)
			if(vis[j]&&a[j][i]==1) vis1[j]=1;
			for(int j=1;j<=n;++j) vis[j]=vis1[j];
		}
		w/=2;
	}
	cout<<ans;
	return 0;
}
/*
戏一折，水袖起落。
唱悲欢，唱离合，无关我。
扇开合，锣鼓响又默。
戏中情，戏外人，凭谁说。
贯将喜怒哀乐都融入粉末，
陈词唱穿又如何，
白骨青灰皆我。
乱世浮萍忍看烽火染山河，
位卑未敢忘忧国，
哪怕无人知我。
台下人走过，不见旧颜色。
台上人唱着，心碎离别歌。
情字难落墨，他唱一曲，来舍。
戏幕起 ，戏幕落，谁是客。 
*/

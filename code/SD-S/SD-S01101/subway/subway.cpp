#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
int c,n,m,d,q,w[500005],k[1000],ans[505][505];
unordered_map<int,int>a[505],t[505];
vector<pair<int,int>>vec[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			vec[a[i][j]].push_back({i,j});
		}
	}
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=n;i++) ans[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=vec[i].size();
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<len;k++)
			{
				pair<int,int>x=vec[i][j],y=vec[i][k];
				ans[x.first][y.first]=ans[y.first][x.first]=min(ans[x.first][y.first],t[x.first][x.second]+t[y.first][y.second]);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
		}
	}
	while(q--)
	{
		int xr,yr;cin>>xr>>yr;
		int sum=w[xr]+w[yr];
		int lenx=vec[xr].size(),leny=vec[yr].size();
		int res=9e18;
		for(int i=0;i<lenx;i++)
		{
			for(int j=0;j<leny;j++)
			{
				pair<int,int>x=vec[xr][i],y=vec[yr][j];
				res=min(res,ans[x.first][y.first]+t[x.first][x.second]+t[y.first][y.second]);
			}
		}
		cout<<res+sum<<"\n";
	}
	return 0;
}
//这题面是人写的吗，读完题会了然后一直读错题以为假了5点半读对题的来了 
//此生仅有的去wc的机会死在了T2题面我真气笑了，什么叫你地铁站之间都有路径可达然后你样例给了个不可达的然后你地铁可以反着开 
//失败贯穿人生始终 
//已经开始哭了  
//用了8分钟写完过了所有大样例，哈哈
//我好难过 
//Vae_L或许，只能是个失败者吧
//总是期待着下一次赢回来水平也在提高却总是因为奇怪的原因输呢
//又或许这些都是理由，根本原因只是水平不够
//NOIP那真的，就是此生最后的机会了
//求求你，让我到时候赢一次 
//疑似会了T4的n^2吗，可那又有什么用，写不完了 
//100+100+40+50或许会是有wc的分数，只不过现在只能以一个小丑的分数离场了
//甚至都不一定有7级毕竟这个T2如此人均
//哈哈 
//失败贯穿人生始终 
//一旦T3或T4有一个是简单题那我就倒闭了
//感觉同学是不是，在这套题下都能去wc
//不知道该说什么了
//似乎，我一直是唯一的失败者啊
//真的，会有正常人类打出我这样的比赛过程吗
//也没有正常人类会打的比我低吧 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

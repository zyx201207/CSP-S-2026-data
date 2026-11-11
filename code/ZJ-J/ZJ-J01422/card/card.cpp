#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
long long n,m;
long long a[500005];
long long ans[300003];
long long cnt=0;
bool flag[500005]={};
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			flag[j]=0;
		}
		cnt=0;
		for(long long j=i;j<=n;j++)
		{
			for(long long k=j-1;k>=i;k--)
			{
				if(a[j]==a[k]&&!flag[k])
				{
					for(long long p=k;p<=j-1;p++)
					{
						flag[p]=1;
//						cout<<i<<" "<<k<<endl;
					}
				}
			}
		}
		for(long long j=i;j<=n;j++)
		{
			if(!flag[j])
			{
//				cout<<i<<" "<<j<<endl;
				ans[a[j]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10:50 du wan ti le.
gan jue ke zuo a.shi jian bu zhi dao gou bu gou.
suan le hai shi da bao li ba.wen yi dian
11:00 kai gan
qiao ke li hao chi=w=
mo ming si kao Trick||Treat shi shen me yi si.
qu nian mao si shi shang shan ruo shui?
gang kai shi bao wo hai yi wei yao Tire Tree le.
n^3 bao li hao hao da.jiu ta le.lan de duo da le(?)
ke neng ba,qi shi ye mei you kan chu qi ta xing zhi......
11:23 jie shu le.jiu zhe yang ba.fa zuo lai le
jian cha wen jian qu le.

ok jian cha wan le.xiao zuo wen jiu xie zai zhe ba^_^
//freopen("card.in","r",stdin);
//freopen("card.out","w",stdout);
(shi tu shang mi huo xing wei da shang O.o)(dao di wei shen me mei you zhong wen shu ru fa a wei!!)
hao ba qi shi jin tian yi hou jiu AFO le TT
ben lai qu nian jiu shuo AFO le,jie guo ju ran you da le yi nian
zhe yi nian da de hao kai xin =w=
hao duo yi qian de peng you dou bei gao zhong ti qian zhao zou le.kong bei qie.ban li shao le hao duo ren(wo jue dui bu shi yin wei cheng ji bu hao cai mei bei zhao zou de......)
shi ba@pwx(hao ba sui ran bu zhi dao zhe ge da xue ba hai hui bu hui shang luo gu)
hai you na ge yi jing shang gao zhong le de@ypy
hai you na tiao gen wo yi yang ma shang tui yi de e yu@yzm
hao xian mu na ge yong yuan bu yong tui yi(ke neng?)de BIG_J,yi ji hai shi ge jin pai ge.o,ye you ke neng suan shi tui yi xuan shou le@jyj
yi ji gan xie na dui lao fu qi yi zhi yi lai de zhi chi!
wo chang chang zhui yi guo qu......
ran hou wang le,bu hui xie tui yi ji zen me ban?
xi wang bu shi zhen de AFO ba,gao zhong hai xiang zai he oi guo yi nian ne.
dan shi wo zhen de hao cai TT
zhen de tui yi ji wo zhong wu xie wan,xia wu kao chang li zai xie(yan su)
qi shi ye you ke neng bu xie le,zhou mo zuo ye dou bu bu wan le
xi wang zai jian TT

zui hou,wo jiang da han:
Zhou Shen nb!Zhou Shen rong yu!nan ning kua nian jian!
piao bo zhi yu wo men xiang yu~~~yin yue shi quan shi jie de liang yao!
(ci chu ying you yan chang hui chang de hao yun lai hhh)
zai yi ci zai jian zai shuo yi ju zai jian zai wo mei fan hui zhi qian~
--Zhou Shen<zai yi ci jian mian>
hai hui zai jian de dui ma!

CCF I LOVE YOU!!!
*/
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
long long n,m;
long long a[500005];
long long box[500005];
long long l,r;
long long sum[500005];
long long ans;
bool flag;
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
//	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		box[i]=1;
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+a[i+1]-a[i];
	}
//	for(long long i=428100;i<=428134;i++)
//	{
//		cout<<a[i]<<endl;
//	}
//	cout<<sum[4328131]<<" "<<sum[428132]<<endl;
//	cout<<a[0]<<" "<<a[1]<<" "<<" "<<a[2]<<" "<<sum[0]<<" "<<sum[1]<<endl;
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<i<<" "<<a[i]<<endl;
//	}
	for(long long i=2;i<=n;i++)
	{
//		cout<<i<<" "<<m<<" "<<l<<" "<<r<<" "<<ans<<endl;
		while(m-(a[i]-a[i-1])*box[i-1]<0&&l<=r)
		{
			m+=sum[r-1]-sum[l-1];
			box[r]--;
			l++;
		}
		if(m-(a[i]-a[i-1])*box[i-1]>=0)
		{
			m-=(a[i]-a[i-1])*box[i-1];
			box[i]=box[i-1]+1;
			r=i;
			ans=max(ans,box[i]);
		}
//		if(ans==315275)
//		{
//			cout<<"!"<<i<<" "<<m<<" "<<l<<" "<<r<<" "<<ans<<endl;
//			continue;
//		}
//		if(!flag&&ans==315276)
//		{
//			cout<<"!"<<i<<" "<<m<<" "<<l<<" "<<r<<" "<<ans<<endl;
//			flag=1;
//		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
wo fang qi le,da yang li4 zen me yong yuan cha 1 TT

froepen("crystal.in","r",stdin);
froepen("crystal.out","w",stdout);

kan le yi yan hou mian de ti zhen de quan dou bu hui le TT.
jie zhe xie zao shang de AFO ji.
mei xiang dao guo le yi nian yue fa cai le.
hao nan shou
T1 ying gai bu hui chao guo huang,ke xi hai shi mei xie hao
na fen qu jian [0,100].kong bu
hou mian san ti kan wan ti mian jiu fang qi le.bao li dou bu hui.
bu tai zhi dao zen me ping jia le TT
wo chang chang zhui yi guo qu......
xiang dang nian qu nian zhen shi chun feng de yi a.T1 yi yan chu jie lun,ban ge xiao shi AC
jin nian wan le,liang ge xiao shi mei AC.hhh.
ai......zao shang T1 ye gua le,xie cheng DE le.
zui hou yi ci ye bu zhi dao gai shuo shen me le.
CCF I LOVE YOU.yi ding yao shu ju shui yi dian a!
zheng qu yi xia wan yi you san deng ne ToT
qi shi xue bian cheng ye you si nian le ba.huang fei le hao jiu.you dian xiang ba zi ji da si
suan le,jiu zhe yang ba,bi jing ye gei wo dai lai le hen duo
yi zhi zhuan zhu whk de hua wo dou bu zhi dao wo xian zai hui shi shen me gui yang
xie xie oi!ovo
you yuan de hua huo xu gao zhong zai jian?huo zhe da xue?ke neng ba.xi wang ba ovo
qu nian ye xie guo tui yi ji,hou lai jue ding le yi xia you jian chi le yi nian,ye shuo bu ding ne^^
"shuo wan zai jian,hai neng zai jian"--Zhou Shen<guo jin qian fan>
zai jian de hua wo ying gai hui bian qiang de!(dian tou)=w=
mei you wen cai zhi you gan shou de yi pian tui yi ji?bu guan le.hao liao cao you you shen me ban fa.bi jing wo de oi sheng ya bi zhe hai yao liao cao.
os:hao xiang dai zhe xian zai de ji yi chong kai a.
luogu uid:wang le.dui.yong hu ming @Zhouzhiyi0929.
ji yi li by bike:ToT
zai ci ming xie@BIG_J @pwx @ypy @yzm(zhe ge feng zi bu suan) deng deng bang zhu guo wo de ren!
zhu ni men neng tian tian kai xin ya!
(yi si chu le BIG_J dou yao tui yi le ne......kong bei qie)
dan shi!wo fa xian!AFO shi Away From OI,na me,TLEO jiu shi Time List Eat OI,ACO jiu shi Ate CE OI,AKO jiu shi Apt Kill OI,CEO jiu shi zong cai,MLEO jiu shi Mum Limit Eat OI,WAO jiu shi Why Ate OI,UKEO jiu shi UFO Knife Eat OI.
hen xian ran,zhe xie dou shi shi shi.
hai shi hen xiang wen wo wei shen me zhao bu dao zhong wen shu ru fa.
you yuan zai jian,mei yuan ying jian.(en.emmm.dui de)
wo hai hui hui lai de(ying gai ba!)

zui hou,Zhou Shen niu bi bu jie shi!
wo da suan qu xie T5 le^^

CCF I LOVE YOU
*/

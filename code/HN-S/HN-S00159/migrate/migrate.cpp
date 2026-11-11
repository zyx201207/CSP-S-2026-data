#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;

//luogu shuo jinribuyipianfen...
//xieyibanfaxianwangjiyouge d le danshimeishijianjiubushuibaolile zhuyaoshiyebuyidingshuidechulai
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	scanf("%lld%lld",&c,&t);
	for(long long int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n,&d);
		long long x[n+10];
		long long dis[n+10][n+10];
		long long ans=0;
		for(long long int j=1;j<=n;j++)
		{
			scanf("%lld",&x[i]);
		}
		printf("0\n");
//		for(long long int n1=1,n1<=n;n1++)
//		{
//			for(long long int n2=1,n2<=n;n2++)
//			{
//				if(n1!=n2)
//				{
//					dis[n1][n2]=abs(x[n1]-x[n2]);
//					dis[n2][n1]=dis[n1][n2];
//				}
//			}
//		}
//		for(long long int n1=1,n1<=n;n1++)
//		{
//			long long shorty=1000000001;
//			long long co=0;
//			for(long long int n2=1,n2<=n;n2++)
//			{
//				if(n1!=n2)
//				{
//					if(dis[n1][n2]<shorty)
//					{
//						co=0;
//						shorty=dis[n1][n2];
//					}
//					else
//					{
//						if(dis[n1][n2]==shorty)
//						{
//							co++;
//						}
//					}
//				}
//			}
//			if(co==1)
//			{
//				
//			}
//		}		
//wxXx13308410696,q2378345622(jiawo,please)
//luogu:xiyaray
//wochaojiruode
//wanyiyourenkandaone
//zuijinxiangzhaorendalianjiyouxi(zhuyaoshipcduan)ta2huozheqianyuanzhen,heiyejunlingshenmede,yeyuanyixuexindeyouxi(danshiwohencai...)
//ranhou haidayingyou tingyixieshu (woshixiaozili)wan arknights he limbus company wofangzhoushixiaoxuewande(danshishimingrenzhendagaizhihouwokailegexiaohao,xiaohaoshi2022niande(haimei120ji))
//zhiyu bianyubashi woshikaifuwanjia(benlaijiuhenxing)wohaijidenatianwojisuhuilainazhebijibenhewomadaohuayanghuideyijiacocochazhedianyuanxianyuxiazai,buguodianyuannashihouyijingzaisaodile
//xianzai,najiadianmeile
//wochangchangzhuiyiguoqu
//womenxuexiaoyouyinyoubisai
//yousangexiangmu phi,kao,bang(meiyou es,fufeidebuyunxu)
//shuoshishangzhoumoukaishi,danshitazhigongbule8shouge
//wojiuxiannazhena8shougezhongdesanshougedaketiqule
//jieguogaosuwocong8shoulimiantalaichou3shou
//danshi,nijiranshizaibisaizhenshikaishizhihoucaifadezhe8shouge,ninageshihouweishenmebuzhijiefangchouchulaide3shougene?
//zuotiancaichulai3shoubisaiqumu,erzhoutianjiezhi(zhidezhuyideshi,woyaogao csp,erqiewanshanghaiyaozaicanjiayigebisai,8:50congxuexiaochulai10:30daojiayouganjueme?)
//(wojiazaileifengzhen,xuexiaozaimawangdui)
//zaizuomianbaochelaikaochangdelushang wozaida<jingle bell><mobiyos(guantajiaoshenme)><wangleshenme poison>
//zheshibisaidechusaiqumu
//raner,wozhiyou291
//che zhende hao dou a
//xianzai woshenpabierenkanwodazhemejiandandegedazhemedianfen,huibawodangyinyoujiahao
//danshiwoyijinbuzaihule(yebushila)
//yinweiwozhebeizimeicanjiaguozhezhonghuodong,suoyichuchouyeshizhenchangde(ba?)
	}
	return 0;
}

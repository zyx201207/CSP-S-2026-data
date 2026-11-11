#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long k[800000];
unsigned long long k1[800000];
//long long qzh[800000];
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
//wo zhen de zhu shi freopen le me
//CRYst11l,ln
//MaGaRape`Out
//foropen()
//zhe xie ying gai bu suan wei gui ba
//wo mei zuo bi ye mei ma ren
//suiranyijinjieshule
//danshi rp++
//woyaotuiyile,suiranwokennengjiuconglaimeiyou"zaiyi"guo.zuihouyi csp-j erdengshouwei.qishinaciwoyousandaotidechenxubujianle(buyinggaia)danshidiyidaotiyou100fen.
//yingweinagetimukeyituichuyigegongshi,dairujisuanjiuhaole
//shuoqilaiwohaibaoleluogutigaozudewangke.danshidajiataiqianglewowanquanmeitingdong.
//ganjuetongshilangfeileqian,wodeshijian,fumulaoshi(baokuowangkelaoshi)duiwodeguanzhu(zhuyaoshihaimeichenji)
//woxiezhegedeshihouhaopabianshangrenkandao,huihenganga(erqiewanyitahuaiyiwozuobizenmeban)
//danshizhemeshidedaimajueduibushizuobichulaide.wolianxianduanshuheyouxianduiliedoubuhui
//woshishuo,zuobifennshumeinamedi
//diyitibuneng100nawohaiyoujihuime
//fanzhenwoxianzaigaozhongle,yebuzhiwangkaozhegjingsida
//womenxuexiaoyizhoucaiyijieke,zhegeyuecaimeizhouduoyijiewanzixiyonglaigaozhege.
//woshuodeshichangshashiyan,sidawuxiaopaidi10denage
//wodapaiqule(ganjuebixiaokonglonghaowan)
//update(30 seconds ago)shenmejiaozuihoubanxiaoshifabut2dekanwu 
//yaoshiyoumeiduchuwodedaima,nawobushilianmihuoxinweidashangdoushangbuliaoleme
//UPDATEAGAINyougerenguolaigenwomenshuobuyaodongzhangxiwang,xiaoxinwanjiebubao(wodanxindejiushizhege)
long long pjz=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
//		qzh[i]=qzh[i-1]+k[i];
		pjz+=k[i];
	}
	if(pjz*1.0/n-pjz/n>=(pjz/n+1)*1.0-pjz*1.0/n)
	{
		pjz=pjz/n+1;
	}
	else
	{
		pjz=pjz/n;
	}
//	printf("%lld",pjz);
	sort(k+1,k+1+n);
//	for(long long int i=1;i<=n;i++)
//	{
//		printf("%lld ",k[i]);
//	}
	long long int l=1,r=n;
	long long mid;
	while(l<r)
	{
//		printf("%d ",mid);
		if(l+1==r)
	 	{
	 		if(pjz-k[l]<=k[r]-pjz)
	 		{
	 			break;
			 }
			l=r;
			break;
		 }
		if(l==mid)
		{
			break;
		}
		mid=(l+r)/2;
		if(k[mid]<pjz)
		{
			l=mid;
			continue;
		}
		if(k[mid]>pjz)
		{
			r=mid;
			continue;
		}
		l=mid;
		break;
	}
	long long d=l;
//	printf("%lld",d);
	unsigned long long ans=1;
	unsigned long long zc=0;
	for(long long int i=d-1;i>=1;i--)
	{
		k1[i]=k1[i+1]+k[d]-k[i];
//		k2[i]=k2[i+1]+k1[i];
		if(k1[i]>m)
		{
			break;
		}
		zc++;
	}
//	printf("%lld %lld\n",d,zc);
//	for(int i=1;i<d;i++)
//	{
//		printf("%d ",k2[i]);
//	}
	long long forevercost=0;
	for(long long int i=d+1;i<=n;i++)
	{
		if(k[i]==k[d])
		{
			zc++;
			d++;
			continue;
		}
		long long jiarucost=(i-(d-zc))*(k[i]-k[d])-forevercost;
		if(k[d-zc]+jiarucost<=m)
		{
			m-=jiarucost;
			forevercost+=k[i]-k[d];
			zc++;
			d++;
		}
		else
		{
			if(zc>0 and k[d-zc+1]+jiarucost-k[i]+k[d]<=m)
			{
				m-=jiarucost-k[i]+k[d];
				forevercost+=k[i]-k[d];
				
				d++;
			}
			else
			{
				break;
			}
		}
	}	
//	printf("%lld ",d);
	printf("%lld",zc+1);
	return 0;
}

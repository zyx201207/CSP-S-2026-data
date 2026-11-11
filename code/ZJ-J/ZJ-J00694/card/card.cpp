#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=n;i>0;--i){
		ans[a[i]]+=i;
		for(int j=i;j<=ans[a[i]];++j)
			if(a[j]!=a[i])ans[a[j]]-=i;
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
//you ji ke neng zhong ying hun yong,sorry qwq
//ya suo bao mi ma:Trick||Treat!
//you ji:
//zhu yi dao mei you zhong wen shu ru fa
//8:48 T1test AC
//8:53 kai T2
//9:30 T2test AC
//9:38 kai T3
//9:56 T3test AC(chu le test6 wei ce)
//10:00 Dev-C++ ka zhu
//10:01 chong xie T3 code
//10:06 T3test AC
//1h20minkaiT4 ni gao su wo zen me shu?
//xiang xiang T4 si lu ba:
//bao li:mei ju ke guo test 1~12,48pts
//wei shen me wo kan zhe xiang dao ACzi dong ji he Trie Tree le?
//wo bu hui zhe xie a!
//bu zhun shuo wo P
//bu ke yi,zong si lin
//zhu yi dao da chu yi ge shu deng tong yu qing chu shang yi ge shu zi hou de all numbers
//zhu yi dao yi ge shu zi zhi neng zai qian mian you shu zi shi bei qing chu
//xie dao zhe li yi jing guo qu le 10min
//mian xiang shu ju bian cheng:
//O(n log m)orO(m log n)or(n log n)or O(m log n)
//suo yi ji zi neng guo 15e10 ma?
//ying gai bu xing ba
//bu dui
//bi xu zhi shao you n,cai ce O(nlogn)orO(nlogm),dan m xiang bu dao you shen me guan xi
//shi shi DP?
//mao si ke neng si hu hao xiang ying gai da gai yong bu liao DP...
//hao xiang AK a!
//jiu cha zhe ti le!
//mu qian zhi xiang dao O(nm)
//you dian xiang dan diao zhan,dan fu za 1e8 dian dian
//zong bu neng dui yu mei ge numbers dou kai yi ge dan diao zhan ba?
//xia ku le
//you shi 10min guo qu le(re)
//wo yi ji ku
//zhu yi dao ru guo bu zai mou yi ju zhi ke neng shi yi xia liang zhong qing kuang:
//1.bu zai pai dui nei
//2.bei qing chu le(bei dong)
//wo men ke yi jiang di yi zhong qing kuang zhuan hua wei di er zhong
//zai zui kai tou tian ge 0,zai mei ge i qian mian ye tian ge 0
//zhe yang jiu ba 1->2 le
//chu ti ren gei m ken ding shi you yuan ying de
//ba cheng shi yao kai ge a[n][m] lai zhe
//dan ke neng hui MLE
//fan tang le shi yong lai shu chu de
//neng fou yu chu li mei ge qing chu qu jian?
//yi si bu xing
//neng bu neng yong xian duan shu a(doge)
//you guo qu le 10 min
//suan le,zhi neng xie bao li le
//bu dui,ke yi de chu yi ge shu de da an wei zui hou yi ge gai shu cun zai ji lun
//na me dui gai shu qian hou jing xing guan cha,ru mei bei qing chu ze
//you guo qu le 10min
//dan shi ji shang bu neng zhe me zuo
//you dian xiang cha fen
//xia ku le,T4 ying cheng sha le
//zui hou 5min le
//555
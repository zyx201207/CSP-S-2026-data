//TYZ lizihan SN-J00645

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[500005],lst[500005],r[500005],dp[500005],ans[500005];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--){
		if(lst[a[i]]==0)lst[a[i]]=i;
		r[i]=lst[a[i]];
	}
	for(int i=1;i<=n;i++)dp[i]=1;
	for(int i=1;i<=n;i++){
		if(r[i]<n)dp[r[i]+1]+=dp[i];
		ans[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	return 0;
}

//8:35 T1
//8:44 T2 JT2 nan!!!
//9:13 T3 zhi jie tan
//9:25 T4 ???
//9:47 ak???
//T4 tang dp, T1<T3<T4<T2
//orange yellow yellow yellow
//no boom 0 no gua fen
//wei shen me wo de card4.ans shi gun mu
//I want to play delta force!!!
//CSP-S --> 1=
//lougu:1620651
//how to use NOI Linux???
//-----------------------------------------------------------------------------------------------------------------------
//lai zi zhong yuan yi qun huo ban,jie lu dong nan shan.chen yuan nan jin mo dui han chuang,bu jue ru lv chi xiang an.
//bing cheng jian nian zhuo jue yi zhi,qian xiu dong nan shan.ning jing zhi yuan feng yu sheng xiang,bu jue ru lv chi xiang an.
//xiang huo zai yu zhong shao ji shi ge shu he han.xue mai xiang lian yi fang ku xing shan.
//long zhu jiu zhuan shi er jin guang,fan zhi wu yue he san jiang.
//xiang huo zai yu zhong shao ji shi ge shu he han.xue mai xiang lian yi fang ku xing shan.
//long zhu jiu zhuan shi er jin guang,fan zhi wu yue he san jiang.
//------------------------------------------------------------------------------------------------------------------------
//jin zun jing jiu dou shi jian,yu pan zhen xiu zhi wan qian.
//ting bei tou zhu bu neng shi,ba jian si gu xin mang ran.
//yu du huang he bing sai chuan,jiang deng tai hang xuan man shan.
//xian lai chui diao bi xi shang,hu fu cheng zhou meng ri bian.
//xing lu nan,xing lu nan.duo qi lu,jin an zai???
//chang feng po lang hui you shi,zhi gua yun fan ji cang hai!!!
//------------------------------------------------------------------------------------------------------------------------
//ba shan chu shui qi liang di,er shi san nian qi zhi shen.
//huai jiu kong yin wen di fu,dao xiang fan si lan ke ren.
//chen zhou ce pan qian fan guo,bing shu qian tou wan mu chun.
//jin ri ting jun ge yi qu,zan pin bei jiu zhang jing shen.
//------------------------------------------------------------------------------------------------------------------------
//ming yue ji shi you???ba jiu wen qing tian.bu zhi tian shang gong que,jin xi shi he nian???wo yu cheng feng gui qu,you kong qiong lou yu yu.gao chu bu sheng han,qi wu nong qing ying,he si zai ren jian???
//zhuan zhu ge,di qi hu,zhao wu mian.bu ying you hen,he shi chang xiang bie shi yuan,ren you bei huan li he,yue you yin qing yuan que,ci shi gu nan quan.dan yuan ren chang jiu,qian li gong chan juan.
//------------------------------------------------------------------------------------------------------------------------
//qing li si nian chun,teng zi jing zhe shou ba ling jun.yue ming nian,zheng tong ren he,bai fei ju xing,nai chong xiu yue yang lou,zeng qi jiu zhi,ke tang xian jin ren shi fu yu qi shang,zhu yu zuo wen yi ji zhi.
//yu guan fu ba ling sheng zhuang,zai dong ting yi hu,xian yuan shan,tun chang jiang,hao hao shang shang,heng wu ji ya,zhao hui xi yin,qi xiang wan qian.ci ze yue yang lou zhi da guan ye,qian ren zhi shu bei yi.
//ran ze bei tong wu xia,nan ji xiao xiang......hou mian shi sha???
//ruo fu yin yu fei fei,lian yue bu kai,yin feng nu hao,zhuo lang pai kong,ri xing yin yao,shan yue qian xing,chang lv bu xing,qiang qin ji cui,bo mu min min......hou mian dou wang le
//------------------------------------------------------------------------------------------------------------------------
//zui weng ting ji di yi ju shi sha lai zhe???
//------------------------------------------------------------------------------------------------------------------------
//sheng xia de hao xiang dou bu hui
//10:26
//what can I do???sleep!!!
//shui bu zhao
//10:51
//la la la
//try to use xu ni ji
//11:12
//tai hao yong le
//11:30
//suan le bu xie le,check and sleep

#include<bits/stdc++.h>
using namespace std;
int c, t;
void __solve(){
    long long n, d, x[5005];
    cin >> n >> d;
    cin >> x[1] >> x[2];
    if(n>5000){
        if(d>(x[2]-x[1])&&d<=2*(x[2]-x[1])){
            cout << n-3;
        }else{
            cout << 0;
        }
        return;
    }
    for(int i=3; i<=n; i++){
        cin >> x[i];
    }
    int dp[5005][5005][2], ans=0;
    for(int i=1; i<=n; i++){
        for(int j=i-1; j>=1; j--){
            if(x[i]-x[j]<=d){
                for(int k=1; k<=j; k++){
                    if(dp[k][i][0]>dp[k][j][0]+dp[j][i][0]){
                        dp[k][i][0]=dp[k][j][0]+dp[j][i][0];
                        dp[k][i][1]=dp[k][j][1]+dp[j][i][1];
                    }else if(dp[k][i][0]==dp[k][j][0]+dp[j][i][0]){
                        dp[k][i][1]+=dp[k][j][1]+dp[j][i][1];
                    }
                }
            }
            if(dp[j][i][1]==2)ans++;
        }
    }
    cout << ans << endl;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        __solve();
    }
    return 0;
}
// some songs 1
// fan wu tuo bang
// fanwutuobangzhongdezhengduo
// bayuanyangjiaosuichengfenmo
// xinlingyebeiguashangmensuo
// kanbuqingdenghuo
// danwohaixiangzuoxieshenme
// qishihaoxiangyaoshuhenduo
// qingnidengdengwo
// qingnidengdengwo
// liangkuaiwudeqianzibi
// dongpinxicoudeciju
// wangxiangyongtazhengjiuni
// shunbianzhengjiuwoziji
// zhiyinweininakewangziyoudexinzang
// kunzaiyizhangmeikongxidewang
// womendezhouweibingfeimeiguangliang
// zhishitaiyaoyanjiangwomenzhuoshang
// zaizhegeshijienanmianhuimimang
// danbiezaibaxiaodaodaizaishenshang
// zhishaowohaizaiweiniergechang
// zaiheianmanchangdefanwutuobang
// jibian
// women
// dozai
// zheheianmanchangdefanwutuobang
// benjiuxiangyaozhengtuodeshenghuo
// zuochubuxiangzuodechengnuo
// liecheshangzuocuozhandechengke
// kunhuozhechenmo
// danwohaixiangzuoxiashenme
// qishihaixiangyaoshuohenduo
// qingnidengdengwo
// qingnidengdengwo
// fazheguangdebanpingmi
// huluanhengchandexuanlv
// danshihaoxiangzhengjiuni
// tongshizhengjiuwoziji
// jiuqingnifangxindadangengwangweisiyi
// maibuxiangqianbiehaipashiqu
// meiyoufanxiarenhecuodeni
// zaiwoxinlizhiyongzhuziji
// zheduanhuluanpincoudeciyu
// ruguoshangdaoniyeqingniwangji
// danruoniyouzhaobudaoyiyi
// xiwangzheshougenengbeijiqi
// huoxiaqu
// huoxiaqu
// huoxiaqu
// huoxiaqu
// zaizhefanwutuobangli
//
// pin jie yi han
// yewandeliangfengchuiguoshenbian
// kongdangdejieshangzhishengxiangnian
// xiangniannitianzhenwuxiexiaoyan
// huitouniquezaojiuyijingbujian
// bukandeshenghuomeitianchongyan
// zheshijiezaoyihuanlerenjian
// ludengchulijiebianyijiuyaoyan
// zhaoliangwoderenshengwunaidecongqian
// tiankonghediqiuzhuanazhuan
// wozhanzaidishangkanleyoukan
// zhongdiangongjiaozhanwurenzai
// yongyuanbucunzaidexiayiban
// wozhanzaiyuandizhuanyouzhuan
// huiyixiangxiangcefanleyoufan
// renshengbengairuhuaxuanlan
// weihewodequerucidepingdan
// mobandegongjiaochuanguoanjingdejie
// erjiligeshengpeizhewobuxiangshui
// renchaomanmansanyingziluozaishenqian
// fengqingqingchuiyoudianlianglingrendanqie
// chengshidenihongmohulewoshixian
// niworensheengzhongkanbudaodejiaodian
// zhengrunamingtianyijiuruoyingruoxian
// kanbudaodeshixiwanghaishiyanjuan
// kuqiluoxiadebushiwodeleishui
// jjiamianxiaorongxiacangzhewodebeiwei
// hunluandeshenghuoquebeichengweizhenggui
// congqianshiguangqianjinyewufahuanhui
// naxieshuoguodehuazaierbianpanxuan
// xiaozheyouxiaozheleixianturanbengkui
// ruguoshijiantazaigeiyicijihui
// wohuibuhuibuxuanzenamelangbei
// buxiangjiuzheyangliuxiayihan
// jibianleishuiyichongmanshuangyan
// jibianxianzaiyiwulihuitian
// yexiangchuanguoshijianjiangnikanjian
// bunengjiuzheyangliuxiayihan
// jibianshenghuotabaibanzulan
// jiedengshanyaonajiurangtayaoyan
// wohaiyoushijianzhaohuizijiqingtian
// tiankonghediqiuzhuanazhuan
// wozhanzaidishangkanleyoukan
// zhongdiangongjiaozhanwurenzai
// yongyuanbucunzaidexiayiban
// wozhanzaiyuandizhuanyouzhuan
// huiyixiangxiangcefanleyoufan
// renshengbengairuhuaxuanlan
// suoyibunengrangtarucipingdan
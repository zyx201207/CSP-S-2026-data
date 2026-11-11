#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,a[500005],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long long i=0,j=0,cnt=0;
    while(i<=n){
        i++;cnt-=(a[j]-a[i-1]);
        while(j<n && cnt+(j-i+1)*(a[j+1]-a[j])<=m){
            cnt+=(j-i+1)*(a[j+1]-a[j]);
            j++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}
/*
mei cuo,shang wu de JS-J01608 ye shi wo.
wo chang chang zhui yi guo qu.
sheng ming shun jian ding ge zai nao hai,wo jiang bei hou de shi jian cai jian,zhe die,quan qu,rou nian cheng tian shang duo duo bai yun.
yun duo zhi jian yi you cha bie:ji yun hou zhong,er juan yun piao miao.sheng ming li zhen han de chang jing lue guo wo de si xu bian yi sheng wu fa wang huai,er geng wei pu tong ping chang de ji yi zai shi jian de chong shua xia zhi liu xia xie xu can hai.zhui yi wan ru ru meng,tai guo qing chu ze wu fa yu yue zi ji de huan xiang,guo fen mo hu que you zhui ru xu wu.zhi you na bo wu jian de shan shui,mian sha xia de nv zi,cai neng man zu wo dui mei de ke qiu.
zhui yi zong zai bu jing yi jian jiang wo guo jin fan huang de zhi ye li.fen bie you chong ju de peng you,tui dao you chong lai de jie dao,zhong zhong xian suo xie zhu zhe wo cong yi ge ju ti de shi ke chu fa yan shi jian de he ni liu er shang.ceng jing de ri zi wu fa chong lai,wo zhi bu guo shi yi ge guo ke.dan wo reng ran ke wang zai mei yi ci zhui yi zhi lv zhong liu xia xian xia shi jian.zai yi ge chang jing qian zhu zu,zai sui yue de meng long zhong liao wang guo qu de zi ji,gan shou jin ke neng duo de tian mi.mei hao de shi guang ceng liu jing wo de shen ti,wo bian xin man yi zu.
guo qu yi jing ning gu,wo dai zhe hui yi xiang qian,zhi shi shi chang shu yu bao guan,hui yi ye zai gai bian zhe ge zi de xing tai,zhe gei wo de zhui yi zhi lv dai lai le yi xie tiao zhan.
wo gai zai na li ting liu?wo wen wo zi ji.
*/

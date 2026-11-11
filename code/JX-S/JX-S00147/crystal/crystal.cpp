#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
bool XX_XXX(int x){
    long long mi=100000000000000000;
    for(int j=0;j+x<=n;j++){
        long long s=0;
        for(int i=1+j;i<x+j;i++){
            s+=a[x+j]-a[i];
        }
        mi=min(mi,s);
    }
    if(mi<=m){
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    //jinxingyigeerfenqidaogunmudezuoyong
    int dan,l=1,r=n;
    while(1){
        dan=(l+r)/2;
        if(XX_XXX(dan)){
            l=dan+1;
        }
        else{
            r=dan-1;
        }
        if(l>r)break;
    }
    cout<<r;
    //1 1 3 4 20 21 21 21 21 21
    return 0;
}
//benlaijiuquanhenduole,Szuhaiquangengduo,taihuiquanqianle
//buganxiangbbequanleduoshao[xiaoku][xiaoku]
//zhewozhenzhaobudaowentizainale
//wokandongweishenmeshicuodele,danshizhenjiewoyexiangbuchulai.
//guoran.gang kai kao de shi hou jian pan yi ge ge qiao de zhen tian xiang,xian zai zhi sheng xia ling xing de jian pan sheng he pin fan de shu biao sheng le(bei
//xiwangzhegedaimanengzaiwosuoxiwangdefanweineinengzhengchangdeyunxing.
//zhongwuchouhualiu
//200chou5cai1dangqi1chongfu
//zuishibai
//hao 2 xiang 3 shuo 1 zhong 1 wen 2
//shang 2 shang 3 xiang 1 lian 2 bian 4 ping 2 sheng 1

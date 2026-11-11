#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ex2[31],bins[32],maxbin,res;
vector<int> bin[32];
vector<int> choosed;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ex2[0]=1;
    for(int i=1;i<=31;i++) ex2[i]=ex2[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;a[i]>ex2[j]&&j<=31;j++)
        {
            if((a[i]&ex2[j])!=0)
            {
                bin[j].push_back(i);
                bins[j]++;
            }
        }
    }
    //for(int k=31;k>=0;k--) cout<<bins[k]<<' ';
    for(int k=31;k>=0;k--)
    {
        //cout<<bins[k]<<' ';
        if(bins[k]<m) continue;
        if(choosed.empty())
        {
            for(auto i:bin[k]) choosed.push_back(a[i]);
            maxbin=k;
            break;
        }
    }
    sort(choosed.begin(),choosed.end(),cmp);
    res=choosed[0];
    for(int i=1;i<m;i++) res=(res&choosed[i]);
    cout<<res;
    // 现在是 10：14
    // 写完 T3 了
    // 好想玩黑流树海
    // 你是一名多边贸易分队玩家
    // 你每天最爱做的事就是打开明日方舟，长期探索，集成战略，黑流树海，开始探索，选择多边贸易分队，林间代步，先手必胜，桃金娘，望，梅
    // 每局最智斗的部分是精二望之前和道中斗智斗勇
    // 进阶望的那一刻，整个世界都为你而闪烁，这可不是什么超大杯的碾压，这是以智取胜
    // 当你二层胡了买到板藤玉米，种子种出恋家果的时候，你发现自己可会运营了
    // 第三层你把估价 325 加工品卖了，搬空了绿商店，D 一下就找到了囊行草和红神迷藏复得之轮果腹，哦天哪！帅斯你冯了！
    // 你直接大跳到居民据点，毫不费力清完了，你可真太有操作了！我的天哪望大哥，天下劫直接从水月炸到黑流树海，那还说啥了兄弟，N18 角标自己批发去吧
    // 你接着一个大跳又到大狗年代理想源，望大哥吃了红神典训绣刃猎犬咖啡，小小理想源何足惧焉
    //               ISW-NO
    //               圆石技艺
    //本场战斗为紧急作战
    //失去联络
    //最终得分
    //325！
    return 0;
}

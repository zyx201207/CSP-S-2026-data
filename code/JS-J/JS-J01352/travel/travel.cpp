#include<bits/stdc++.h>
using namespace std;
int x,y;
string xseat,yseat;
bool f1,f2,f3,f4;
bool check(char c1,char c2)
{
    if((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')) return 1;
    if((c1=='D'||c1=='F')&&(c2=='D'||c2=='F')) return 1;
    return 0;
}
bool check1(char c1,char c2)
{
    if((c1=='B')||(c2=='B')) return 1;
    if((c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')) return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>xseat>>y>>yseat;
    if(x==y) f1=1;
    if(f1&&xseat[1]==yseat[1]) f2=1;
    if(f2&&check(xseat[2],yseat[2])) f3=1;
    if(f3&&check1(xseat[2],yseat[2])) f4=1;
    cout<<f1<<f2<<f3<<f4;

    //哎呦我去原来能打中文
    //但是会不会变成棍斤铐还不知道
    //要不直接提前写游记吧
    //游什么（划掉）
    //8:07 无聊
    //隔壁的到底在干什么
    //为啥他会用 VS Code 啊
    //咖啡好喝
    //这咖啡喝了烧心
    //全省就几个考点是为什么啊
    //还要提前一天过来
    //但是我是本地人hhh
    //8：20 开始播注意事项
    //话说我在这里写一个 F[数据删除] CCF 会死吗
    //今年的一定要水一点口牙
    //明天明日方舟半周年
    //我说你们不要去冲塔露拉强度了
    //她已经没有对手了
    //我敢肯定yj给她留了一手
    //卫！！！我要卫！！！！卫戍协议！！！我们的卫戍协议！！！
    //明日方舟官服 Fatcat胖猫Lv.72头像圣聆初雪，助战德克萨斯与初雪
    //洛谷 Fat__Cat 1289619
    //8：30 ；开始了！
    //密码 Trick||Treat!
    //等下我先写个 T1
    //写完了！
    return 0;
}

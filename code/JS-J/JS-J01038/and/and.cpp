#include<bits/stdc++.h>
using namespace std;
int n,m,a[20010];
int awy(int x,int y){
    int wssb;
    return wssb;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int minn=1000000000;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<minn)minn=a[i];
    }
    cout<<minn;//尝试拿5分吧，诶

    return 0;
}
//目前估分100+68，直接废了，耍起！！！
//只好争取上迷惑行为大赏了awa
//坏了坏了我是文盲，按位与是什么啊（悲    最绝望的四法
//好像想起来了。？
/*
3=11
15=1111
3and15=11

3=11
12=1100
3and12=0
所以是找相同吗

15=1111
12=1100
15and12=1100

学会了
我  是  天  才
去洛谷膜拜我
我叫【封禁帐号】，恩对
☝原因是在谷比赛时看MARKDOWN然后伪装自己是AI，注释了一行密码
我真是扎啤


好了继续自学

31and15and7=7

31=11111
15=1111
7=111
那么
为什么呢
是找它们三个所共有的吗

看看and/3.in

现在是09：46
时间还够我耍



？？？
样例比我命长
阴完了
算了不看了

麻烦上一下迷惑行为awa
叫“自言自语着自学”
*/

#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005],vis[300005],ans[300005];
stack<int> s;
// froepen fropen feropen
// freopen("card.in","w",stdin);
// freopen("card.out","r",stdout);
// int mian()
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for (int i = 1;i<=n;i++)
        cin >> a[i];
    for (int t = 1; t <= n;t++)
    {
        memset(vis, 0, sizeof vis);
        for (int i = t;i<=n;i++)
        {
            if(!vis[a[i]])
            {
                vis[a[i]] = 1;
                s.push(a[i]);
            }
            else
            {
                bool flag = true;
                while(flag)
                {
                    int tmp = s.top();
                    s.pop();
                    vis[tmp]=0;
                    if(tmp==a[i])
                        flag = false;
                }
                s.push(a[i]);
                vis[a[i]] = 1;
            }
        }
        // cout << "case:" << t;
        for (int i = 1; i <= m;i++)
        {
            // cout << vis[i]<<' ';
            if (vis[i])
                ans[i]++;
        }
        // cout << endl;
    }
    for (int i = 1; i <= m;i++)
        cout << ans[i] << ' ';
    return 0;
}
/*
成蒟蒻了
T1暴力打表写了一堆if
T2因为一个小于等于号自己出了3组数据花了50mins才找出问题，至少是过了
T3dfs+剪枝勉强40~50pts。
现在是10:40:31 开始写T4
不管今年拿不拿得到1=
感谢CCF，出题和这么多数据辛苦了，这次特殊性质也比较多，方便我T3拿分，还是很感谢CCF
10:43写完输入
这个VS code的自动格式化好难受，早知道一开始就用Dev了
10:49妈呀哪个**开的窗，给我草稿纸吹地上飘。
T4这个长得好像栈啊，万一就是呢，先模拟着用吧O(nm)的复杂度也是有分的
10:51码完初版，发现对游戏理解出了问题
10:58修好问题，O(nm)的复杂度已解决
11:00写上freopen回去看T3，T4这边已经拿到76pts了。（运气差评测机比较慢的话可能是68pts，最低保底56）
话说这个考场日志要算在文件字节确认表里吗，我反正加上了
T3是个什么算法
期望估分：100+100+50+68=318pts
11:17抽筋了！！！考场上忍痛很难得啊啊啊！！
11:20第一次检查freopen
11:27感觉很饿，对面那个哥们举手5分钟了老师还没过来就难绷
11:31开始骗迷惑行为大赏
11:33第二次检查freopen
11:42好困啊，好想睡觉早上6:50就醒了
11:47第三次检查freopen和文件夹
11:52这应该是最后一次检查了，刚刚用别的软件写了些代码。
把考场当软件体验馆了，感觉都不如VS Code和Dev
11:55准备填写文件字节数确认表
11:58 all right（全部检查完毕）
*/
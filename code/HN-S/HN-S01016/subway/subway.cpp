#include<bits/stdc++.h>
#define int long long
const int MAXN=5e5+10,INF=1e18+7;
using namespace std;
int c,n,m,d,q;
int w[MAXN],k[505],tot[MAXN];//tot[i]计数当前是i的第几条线
int a[MAXN][25],t[MAXN][25];//a[i][j]表示节点i能到第j条线路的编号（20->500),t[i][j]表示i节点第j条线路的站台时间
int f[505][505];//f[i][j]表示从i号线到j号线的最小代价
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)f[i][j]=INF;
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x;
            cin>>x;
            a[x][++tot[x]]=i;
            cin>>t[x][tot[x]];
        }
    }
    for(int u=1;u<=m;u++){
        for(int i=1;i<=tot[u];i++){
            for(int j=i+1;j<=tot[u];j++){
                int ii=a[u][i],jj=a[u][j];
                f[ii][jj]=f[jj][ii]=min(f[ii][jj],t[u][i]+t[u][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int minn=INF;
        for(int i=1;i<=tot[x];i++){
            for(int j=1;j<=tot[y];j++){
                int ii=a[x][i],jj=a[y][j];
                minn=min(minn,f[ii][jj]+t[x][i]+t[y][j]);
            }
        }
        cout<<(minn+w[x]+w[y])<<"\n";
    }
    return 0;
}/*吐槽一下，考场怎么总是莫名其妙地响铃，3点还说“现在考试开始”.猎奇。
嗯对这里是吐槽专区。
申请了linux发现周围的人都好强啊。
考场还是有可爱的同学的。
被压力了。
怎么就几个女生/fn。~~臭男的滚开~~（只是玩个梗无恶意喵）
OK现在开始做梦，《全世界OI能力下降1000倍而我不变》。
不想写T3……又怕T1T2没A。QWQ
妈呀我是什么大心脏吗，T1T2测大洋里的时候如果我的小手表带了，疑似心率检测飙升200（？
可能是太激动了吧……去年第一次考S成功拿下12pts（
今年初二如果没有二等就做不了女队的梦了……真的好紧张……
wc真服了T3T4会打滚木的暴力分。
发现我手真的欠欠的，那个大洋里随手就把打开的页面关掉，又得重新解锁。
哈然后这个快读看着不顺眼，删了！
算了卡个常防止过不了。
啊呀感觉快读像个错的，删了！
最终左右脑博弈结果：还是仅关同步流吧。
浪费20min……
样例解释有问题，这个广播真的好炸耳……
匹诺曹P&DECO*27&胃弱万岁！
*/
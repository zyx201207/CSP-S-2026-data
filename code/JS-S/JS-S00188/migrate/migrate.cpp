#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010],f[310][310],nxt[310],mp[310][310];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t,n,d,ans;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            if(n<=2){
                cout<<"0\n";
                continue;
            }
            int x=d/(a[2]-a[1]);
            if(d<2*(a[2]-a[1])){
                cout<<"0\n";
                continue;
            }
            cout<<max(0ll,n-x*2+1)<<'\n';
        }
        return 0;
    }
    while(t--){
        ans=0;
        memset(f,0x3f,sizeof f);
        cin>>n>>d;
        for(int i=1;i<=n;i++)f[i][i]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n-j;i++){
                if(a[i+j]-a[i]<=d)f[i][i+j]=1,nxt[i]=i+j;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<k;i++){
                for(int j=k+1;j<=n;j++){
                    if(f[i][k]+f[k][j]<f[i][j]){
                        f[i][j]=f[i][k]+f[k][j];
                        mp[i][j]=1;
                    }
                    else if(f[i][k]+f[k][j]==f[i][j])mp[i][j]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)
                if(mp[i][j]==2)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
请告诉我寂寞的时长
那里是否布满花儿的香
在海上漂了很久会觉得岸上很晃
雨打湿了衣裳就适应了海水的凉
海北的路上没有信号
海北的灯光比繁星亮
海北的机车妹匆匆忙
海北的空调像是冬天一样冷得让我
缩成一只小鸟 缩成一只小鸟
可是没有人知道
我是刚刚经过暴风雨回到岸上的船长
会到岸的船长
可我却迷失方向
像是气球一样四处撞……撞……撞……

槟榔一定配香烟才够爽
海北的男孩讲话有些娘娘腔
尽管看上去他们更强壮
但是我有胆量去征服海洋
上天没有给我华丽的皮囊
至今学不会打领结穿西装
海北没有适合我的衣裳
我喜欢光着膀子露出胸膛

吃饱的乌鸦在叫
迟到的学生赛跑
妩媚的夜让我想念我的船
和那些被雨淋湿的海鸟
哭泣的乌云在飘
沉默的大地在摇
我开始怀念热流里
涌来的爆米花味道
*/

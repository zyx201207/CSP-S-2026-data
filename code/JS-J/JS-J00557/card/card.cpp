#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5*1e5+10;
const int inf=0x3f3f3f3f;

int n,m;
int vis[N],cnt[N],idx[N];
int a[N];

void solve1(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[j]=0;
            idx[j]=inf;
        }
        for(int j=i;j<=n;j++){
            if(idx[a[j]]<j){
                vis[idx[a[j]]]++;
                vis[j]--;
                idx[a[j]]=j;
            }else{
                idx[a[j]]=j;
            }
        }
        for(int j=i;j<=n;j++){
            vis[j]=vis[j-1]+vis[j];
            if(vis[j]==0){
                cnt[a[j]]=cnt[a[j]]+1;
            }

        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
}

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        solve1();
    }
    return 0;
}











/*纸牌游戏(card)
【题目描述】
小 Z 正在玩一种单人纸牌游戏。
他有一叠特制的纸牌,共有 n 张,从上到下的点数依次为 a 1 , a 2 , . . . , a n 。每张牌的
点数都是 1 到 m 之间的整数,且每种点数都出现至少一次。
小 Z 将进行 n 局相互独立的游戏。每局开始前,他会将所有牌按原顺序放回牌堆,
并清空桌面。在第 i (1 ≤ i ≤ n) 局中,他跳过前 i − 1 张牌,依次打出第 i 张到第 n 张
牌,这些牌的点数依次为 a i , a i+1 , . . . , a n 。
桌面上的牌始终从左到右排成一行。打出一张点数为 k 的牌时:
• 若桌面上没有点数为 k 的牌,就将这张牌放在最右端;
• 否则,收走桌面上点数为 k 的牌及其右侧的所有牌,再把这张牌放在最右端。被
收走的牌在本局中不再使用。
由上述规则可知,任意时刻桌面上同一种点数的牌至多只有一张。
最后一张牌打出后,本局游戏结束。
例如,若桌面上从左到右的牌的点数依次为 1, 4, 2,则打出一张点数为 3 的牌后,桌
面上从左到右的牌的点数依次为 1, 4, 2, 3。接着打出一张点数为 4 的牌时,桌面上原来
点数为 4 的牌及其右侧的所有牌(点数依次为 4, 2, 3)被收走,再把新打出的 4 放在最
右端,此时桌面上从左到右的牌的点数依次为 1, 4。
你需要帮助小 Z 依次求出,对于每个 i = 1, 2, . . . , m,在所有 n 局游戏中,有多少
局结束时桌面上留有点数为 i 的牌。


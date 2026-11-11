#include<bits/stdc++.h>
using namespace std;
#define gg long long

const int N=5e5+10; //牌堆里卡牌数量的上限
int n,m;
int a[N];
const int M=3e5+10; //卡牌点数上限
bool vis[M]; //记录当前桌面上有没有点数为i的牌
stack<int> now;
int ans[M];

void clear_card(){  //清理桌面
    memset(vis,false,sizeof(vis));
    while(!now.empty()) now.pop();
}
void add_card(int num){  //打牌
    if(!vis[num]){
        now.push(num);
        vis[num]=true;
    }else{
        while(now.top()!=num){
            vis[now.top()]=false;
            now.pop();
        }
    }
}
void ans_card(){  //统计桌面上的牌
    while(!now.empty()){
        ans[now.top()]++;
        now.pop();
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        //开启一局新游戏
        clear_card(); //清空桌面
        for(int j=i;j<=n;j++){ //接下来逐渐打牌
            add_card(a[j]);
        }
        ans_card(); //统计桌面上的牌
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
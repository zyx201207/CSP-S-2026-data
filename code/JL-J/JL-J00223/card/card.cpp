#include<bits/stdc++.h>
using namespace std;
int a[500000],vis[500000],ans[500000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    //点菜：@英伟达，送我一台笔记本电脑
    //没有想到t2t3我不会，我别活了
    //教练说不300+我就不用学了，那明年的这个时候我的洛谷可能已经死了
    //但是------
    //保留节目：luogu关注@zlx2013谢谢喵！！！！！！！！！！！！我就是一个水日子的sb，弱爆了
    //觉得自己码力很强,实际会说不会写，快请视频号上的那个解决哑巴英语的那个老师辅导我oi
    //就这样吧
    int n,m;
    cin>>n>>m;
    for(int i=n;i>=1;i--){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]]){
            for(int j=vis[a[i]];j<i;j++){
                vis[a[j]]=0;
                a[j]=0;
            }
            vis[a[i]]=i;
        }else{
            vis[a[i]]=i;
        }
        for(int j=1;j<=m;j++){
            if(vis[j])ans[j]++;
        }
        for(int j=1;j<=i;j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    //这题思路就是错的，能打多少分纯靠命
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[500001];
int cnt[300001];
int board[500001], p=1;//p为末尾下标
bool flag = true, flag1=false;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    //特殊情况: 性质A (16')

    for(int i = 1; i < n; i++){
        if(a[i+1]<a[i]){
            flag=false;
            break;
        }
    }
    if(flag){
        for(int i = 1; i <= m; i++){
            cnt[i] = i;
        }
    }
    //暴力
    else{
        for(int i = 1; i < n; i++){
            p = 0;
            for(int j = i; j <= n; j++){
                //如果此牌已经存在 删除其后方所有牌
                flag1=false;
                for(int k = 1; k <= p && !flag1; j++){
                    if(a[j] == board[k]){
                        flag1 = true;
                    }
                    if(flag1){
                        p = k;
                    }
                }
                board[p++]=a[j];
            }
            for(int j=1;j<p;j++){
                cnt[board[j]]++;
            }
        }
    }


    //输出
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}

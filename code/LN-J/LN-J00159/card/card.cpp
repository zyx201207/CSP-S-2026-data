#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n,m;
//what ghost!
//I can't answer it!
//100+70+60+0=230pts
//I will go to S in the afternoon
//J is difficult
//CCF why not boom?
//7min left
//It was the worst grade I‘ve got.
//ok,6 min
//It may be my last dance.
//is it a big simulation?
//or math?
//well,it has nothing to do with me
//I love coding,however,I hate CCF

const int MAXN= 5e5+5,MAXM = 3e5+5;
int a[MAXN];
int cnt[MAXM];
bool isA=1;//是否具有性质A单调不降
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i =0 ;i<n;i++) cin>>a[i];
    for(int i = 1;i<n;i++){
        if(a[i]<a[i-1]){
            isA = 0;
            break;
        }
    }
        int cur = 0;
        for(int k = 0;k<n;k++){
            for(int i = k,j = 1;i<n&&j<=m;j++){
                while(a[i]==j){
                    cur++;
                    i++;
                }
                //结算这个牌的数量奇偶
                if(cur&1){
                    cnt[j]++;
                }
            }
        }
        for(int i = 1;i<=m;i++) cout<<cnt[i]<<" ";
}

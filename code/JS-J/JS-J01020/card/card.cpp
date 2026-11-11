#include <bits/stdc++.h>
using namespace std;
int a[500005];
int desk[500005];
int ans[500005];
bool vst[500005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++)cin >> a[i];
    for(int i = 1;i<=n;i++){
        int tot=0;
        memset(desk,0,sizeof(desk));
        memset(vst,0,sizeof(vst));
        for(int j = i;j<=n;j++){
            if(vst[a[j]]){
                while(desk[tot]!=a[j]){
                    vst[desk[tot]]=0;
                    ans[desk[tot]]--;
                    tot--;
                }
            }
            else{
                desk[++tot]=a[j];
                vst[a[j]]=1;
                ans[a[j]]++;
            }
        }
    }
    for(int i = 1;i<=m;i++)cout << ans[i] << ' ';
    return 0;
}
//11:15 理论上来说能拿48pts
//100+100+15+[24,48]=[239,263]
/*
又一遍又一遍那天相见
又一遍又一遍思绪万千
在夏日尽头的你能否回忆起
最初时的誓言
繁星呐坠落于海的那边
明月也倒转向银河倾斜
故事的最后一页 由我来写

盛夏的黄昏 你在树荫下走神
蝉鸣与落叶 微风拂过我心神
在哪里在哪里守候着你
就算来年我们也会分离
思念情绪化作泪水 哀伤多几分

…………

都给我去听！！！（
*/

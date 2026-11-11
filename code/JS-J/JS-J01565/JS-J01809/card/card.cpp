#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200005];
int vis[300005];
int flag[300005];//zhegeshushangcichuxiandedifang
int cnt[300005];
int flag1[300005];//zaimeijudeshuzaibutongshujiandezhuangtai

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    bool flag2=false;
    for(int i=1;i<=m;i++){//meiju pai dianshu
        for(int j=n;j>=1;j--){
            if(vis[a[j]]){
                flag1[j]=flag1[flag[a[j]]];
                flag2=true;
            }else{
                vis[a[j]]=1;
                flag[a[j]]=j;
            }
            if(a[j]==i){
                flag1[j]=1;
            }
            if(flag1[j+1]&&!flag2){
                flag1[j]=1;
            }
            if(flag1[j]){
                cnt[i]++;
            }
        }
        flag2=false;
        for(int k=1;k<=n;k++){
                if(flag1[k]){
                    flag1[k]=0;
                }
            }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
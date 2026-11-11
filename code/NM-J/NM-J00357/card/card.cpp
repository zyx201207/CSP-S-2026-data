#include <bits/stdc++.h>
using namespace std;
constexpr int CCF=5e5+5;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int a[CCF]{};
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int cnt[CCF]{};
    for(int k=1;k<=n;k++){
        int pd[CCF]{};
        int en=1;
        int havek[CCF]{};
        for(int i=k;i<=n;i++){
            int j=a[i];//j -> 牌的点数
            if(!havek[j] || havek[j]>en){
                pd[en]=j;
                havek[j]=en;
                en++;
            }else{
                en=havek[j];
                en++;
                
            }
        }
        for(int i=1;i<=en;i++){
            cnt[pd[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
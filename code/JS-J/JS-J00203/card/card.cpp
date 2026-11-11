#include<bits/stdc++.h>
using namespace std;
int n,m,pos,cnt[300005];
int a[500005],guo[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    memset(a,0,sizeof(a));
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    memset(cnt,0,sizeof(cnt));
    cnt[a[n]] = n;
    for(int i = 1;i <= n;i++){
        memset(guo,0,sizeof(guo));
        pos = 1;
        bool flag = 1;
        for(int j = i;j <= n;j++){
            for(int k = 1;k <= pos;k++){
                if(guo[k] == a[j]){
                    pos = 1;
                    flag = 0;
                }
            }
            if(flag){
                guo[pos] = a[j];
                pos++;
            }
        }
        for(int j = 1;j <= pos;j++){
            if(guo[j] == a[n])
                continue;
            cnt[guo[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)
        cout << cnt[i] << ' ';
    return 0;
}

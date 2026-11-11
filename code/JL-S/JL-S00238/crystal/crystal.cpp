#include <bits/stdc++.h>
using namespace std;
bool bj(long long a,long long b){
    return a < b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    long long b[n+1];
    for(int i = 1;i <= n;i++){
        cin >> b[i];
    }
    sort(b+1,b+n+1,bj);



    long long a[n];//qujian
    long long last = -1;
    int o = 1;
    for(int i = 1;i <= n;i++){
        long long d = b[i];
        if(i == 1){
            last = d;
            continue;
        }
        a[o] = d - last;
        o++;
        last = d;
    }
    //ok

    long long q = 1;
    int k = 1;//jiangyaozoudequjian
    long long o3 = 1;  //shishijiankong
    long long ans = -1;
    long long ert = 0;  //he
    long long rdu = -1;   //ruduizuizaodebianhao
    while(1){
        if(k == n){
            break;
        }
        if((a[k] * q) <= m){
            if(rdu == -1){
                rdu = k;
            }
            m = m - (a[k] * q);
            o3++;
            ert += a[k];
            ans = max(ans,o3);
            q++;
            k++;
        }else{
            if(o3 == 1){
                rdu = -1;
                k++;
                continue;
            }
            m += ert;
            o3--;
            q--;
            ert -= a[rdu];
            rdu++;
        }
    }
    if(ans == -1){
        cout << 1;
    }else{
        cout << ans;
    }
    return 0;
}

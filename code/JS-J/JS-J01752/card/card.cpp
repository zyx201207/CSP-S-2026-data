#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m;
int a[500005],b[500005],c[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    bool f = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        c[i] = a[i];
        if(a[i] < a[i - 1]) f = 0;
    }if(f){
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if(a[j] != a[j - 1] || j == i) b[a[j]]++;
            }
        }for(int i = 1;i <= m;i++) cout << b[i] << " ";
        return 0;
    }for(int i = 1;i <= n;i++){
        memcpy(a,c,sizeof(a));
        for(int j = i;j <= n;j++){
            b[a[j]]++;
            int f = j;
            for(int k = j - 1;k >= i;k--){
                if(a[k] == a[j]){
                    f = k;
                    break;
                }
            }if(f != j){
                for(int k = j - 1;k >= f;k--){
                    b[a[k]]--;
                    a[k] = 0;
                }
            }
        }
    }for(int i = 1;i <= m;i++) cout << b[i] << " ";
    return 0;
}//RP++

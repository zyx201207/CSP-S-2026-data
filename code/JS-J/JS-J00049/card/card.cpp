#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[1000005],b[1000005];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int cnt1 = 0,cnt2 = 0;
    int pd = a[n];
    if(pd == 2){
        cnt2++;
    }
    if(pd == 1){
        cnt1++;
    }
    if(m == 2){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                a[j] = b[j];
            }
            for(int j = 1;j <= i - 1;j++){
                a[j] = 0;
            }
            for(int j = i + 1;j <= n;j++){
                if(a[i] == a[j] && a[i] != 0){
                    for(int k = i;k <= j - 1;k++){
                        a[k] = 0;
                    }
                }
            }
            for(int j = 1;j <= n;j++){
                if(a[j] == 1){
                    cnt1++;
                    break;
                }
                if(a[j] == 2){
                    cnt2++;
                    break;
                }
            }
        }
    }
    if(cnt1 > cnt2){
        cnt1++;
    }
    else{
        cnt2++;
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}

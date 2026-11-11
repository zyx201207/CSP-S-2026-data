#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
long long a[MAXN],n,m;

int main(){


    freopen("crystal","r",stdin);
    freopen("crystal","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++) cin >> a[i];
    /*-------------------------------------------------------------------*/
    int Max = a[1];
    for(int i = 2;i <= n; i++) {
        if(a[i] > Max) {
            Max = a[i];
        }
    }
    while(a[n] != Max){
        for(int i=1;i<n;i++){
            if(a[i+1] <= a[i]) swap(a[i],a[i+1]);
        }
    }
    long long c = 0;
    for(int i = 1;i <= n; i++) c += a[i];

    if(m >= c) {
        cout << n;
        return 0;
    }
    int cnt = 0,num = n,coc[MAXN];
/* 😂
 💪👕🖕
   👖
   👣
*/


    for(int j=1;j<n;j++){
        cnt = 0;
        for(int i=num-j;i>1;i--){
            if(m<a[i-1] - a[i]) {
                continue;
            }
            if(m<=0) {
                break;
            }
            m -= (a[i]-a[i-1]);
        }
        coc[j] = cnt;
    }
/*
   😂
 💪👕🖕
   👖
   👣
   😂
 💪👕🖕
   👖
   👣
*/


    int MAx=coc[1];
    for(int i = 2;i < n; i++) {
        if(coc[i] > MAx) {
            MAx = coc[i];
        }
    }
    cout << Max;

    return 0;
}

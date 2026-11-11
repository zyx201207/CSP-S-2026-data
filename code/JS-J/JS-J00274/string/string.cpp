#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    int n;
    cin>>n;
    long long a[n];
    char c[n];
    for(int i = 0;i < n;i++){
        cin>>a[i]>>c[i];
    }
//    int ln = a[0],rn = a[n-1];
    int ln_n = 0,rn_n = n-1;
    long long cnt = 0;
    while(ln_n <= rn_n){
        if(c[ln_n] == c[rn_n]){
            if(a[ln_n] >= a[rn_n]){
                a[ln_n] = a[ln_n] - a[rn_n];
                a[rn_n] = 0;
                rn_n--;
            }else{
                a[rn_n] -= a[ln_n];
                a[ln_n] = 0;
                ln_n++;
            }
        }else{
            if(a[ln_n] >= a[rn_n]){
                cnt += a[rn_n];
                a[ln_n] = a[ln_n] - a[rn_n];
                a[rn_n] = 0;
                rn_n--;
            }else{
                cnt += a[ln_n];
                a[rn_n] -= a[ln_n];
                a[ln_n] = 0;
                ln_n++;
            }
        }
    }
    cout<<cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

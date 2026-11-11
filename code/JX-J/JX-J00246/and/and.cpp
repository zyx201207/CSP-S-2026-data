#include <bits/stdc++.h>
using namespace std;
long long er[32];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    long long xw=-1;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        long long k, s, ws=1;
        cin >> k;s=k;
        while(s>1){
            s/=2;ws++;
        }
        if (xw<ws)xw=ws;
        for(int l=0;l<ws;l++){
            er[l]+=k%2;
            k/=2;
        }
    }
    long long s=0;
    for (int i=xw;i>0;i--){
        if (er[i-1]>=m){
            s+=pow(2,i-1);
        }
    }
    cout << s;
    return 0;
}

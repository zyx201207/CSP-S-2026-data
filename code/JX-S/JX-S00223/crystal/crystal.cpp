#include "bits/stdc++.h"
using namespace std;
long long a[1000000];
long long b[1000000];
long long m,n;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    b[0] = a[0];
    for(int i = 1;i < n;i++){
        b[i] = b[i-1] + a[i];
    }

    int ans;
    int big = n;
    int small = 1;
    while(big-small > 1){
        int mid = (small+big)/2;
        if(is_ans_ok(mid) == 1){
            small = mid;
        }else{
            big = mid;
        }
    }
    if(is_ans_ok(big) == 1){
        cout << big << endl;
    }else{
        cout << small << endl;
    }
    return 0;
}
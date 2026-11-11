#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int x;
    cin >> x;
    int l=1,r=1000,mid,ans;
    while(l <= r){
        mid = (l+r)>>1;
        if(mid >= x) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}

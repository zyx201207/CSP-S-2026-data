#include<bits/stdc++.h>
using namespace std;
struct str{
    long long cnt;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i= 1;i <= n;i++){
        cin >> a[i].cnt >> a[i].c;
    }
    int l = 1,r = n;
    long long ans = 0;
    while(l <= r){
        if(a[l].c != a[r].c){
            long long k = abs(min(a[l].cnt,a[r].cnt));
            ans += k;
        }
        if(a[l].cnt > a[r].cnt){
            a[l].cnt -= a[r].cnt;
             r--;
        }
        else if(a[l].cnt < a[r].cnt){
            a[r].cnt-= a[l].cnt;
            l++;
        }
        else{
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}

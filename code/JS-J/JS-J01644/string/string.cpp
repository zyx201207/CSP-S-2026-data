#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    long long l1,l2,r1,r2;
    l1 = 1,r1 = n;
    l2 = 1,r2 = a[n];
    long long ans = 0;
    while(l1 < r1 || (l1 == r1 && l2 <= r2)){
        if(c[l1] == c[r1])
        {
            long long p = min(a[l1] - l2 + 1,r2);
            l2 += p,r2 -= p;
            if(l2 > a[l1]){
                l1 ++;
                l2 = 1;
            }
            if(r2 <= 0){
                r1 --;
                r2 = a[r1];
            }
        }
        else{
            long long p = min(a[l1] - l2 + 1,r2);
            ans += p;
            l2 += p,r2 -= p;
            if(l2 > a[l1]){
                l1 ++;
                l2 = 1;
            }
            if(r2 <= 0){
                r1 --;
                r2 = a[r1];
            }
        }
    }
    cout << ans << endl;
    return 0;
}

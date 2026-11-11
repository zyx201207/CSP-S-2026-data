#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int a[10086],maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        a[x]++;
        maxn = max(maxn,x);
    }
    for(int i = maxn;i > 0;i--){
        if(a[i] >= m){
            cout << i;
            return 0;
        }
        cnt+=a[i];
        if(cnt >= m){
            cout << i;
            return 0;
        }
    }
    return 0;
}

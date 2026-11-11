#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n,m,a[N],mx,sum,shu[N];
bool vis[N];
void qpl(long long now) {
    if(now == m + 1){
        long long sum = shu[1];
        for(int i = 2;i < now;i ++){
            sum &= shu[i];
        }
        mx = max(mx,sum);
        return ;
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            shu[now] = a[i];
            vis[i] = 1;
            qpl(now + 1);
            vis[i] = 0;
        }
    }
    return ;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(i == 1){
            sum = a[1];
        }else{
            sum = sum & a[i];
        }
        mx = max(mx,a[i]);
    }
    if(m == 1) {
        cout << mx;
        return 0;
    }
    if(m == n) {
        cout << sum;
        return 0;
    }
    if(m == 2) {
        mx = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = i + 1;j <= n;j ++) {
                mx = max(mx,a[i] & a[j]);
            }
        }
        cout << mx;
        return 0;
    }
    mx = 0;
    qpl(1);
    cout << mx;
    return 0;
}

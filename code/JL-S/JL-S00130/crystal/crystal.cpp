#include <bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,m,sum1 = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        sum1 += a[i];
    }
    long long k = sum1 / n;
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i ++) b[i] = abs(k - a[i]);
    sort(b + 1,b + n +1);
    long long cnt = 0,sum = 0;
    for(int i = 1;i <= n;i ++){
        sum += b[i];
        if(sum > m) break;
        cnt ++;
    }
    cout<<cnt;
    return 0;
}


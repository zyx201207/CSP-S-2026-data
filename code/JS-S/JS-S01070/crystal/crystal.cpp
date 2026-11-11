#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum = 1,s[5000010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    sort(a+1,a+n+1);
    s[1] = a[1];
    for(int i = 2;i<=n;i++){
        s[i] = a[i]+s[i-1];
    }
    for(int i = 2;i<=n;i++){
        if(a[i]*i-s[i]>m)break;
        sum++;
    }
    cout << sum;
    return 0;
}

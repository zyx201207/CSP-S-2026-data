#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100010],sum;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a+1,a+n+1);
    long long goal = (sum + m) / n - 1;
    long long num = 0;
    for(long long i = 1;i <= n;i++){
        if(a[i] <= goal) num++;
    }
    cout << num;
    return 0;
}

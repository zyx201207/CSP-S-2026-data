#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    int n,m,y[100000],sum = 0;
    cin >> n >> m;
    vector <long long> a(n+1);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    y[1] = a[1];
    for(int i = 2;i <= n;i++){
            y[i] = y[i - 1] & a[i];

    }
    for(int i = 1;i <= n;i++){
        sum = max(y[i],sum);
    }
    cout << sum;
    return 0;
}


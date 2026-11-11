#include <bits/stdc++.h>
using namespace std;

long long a[200005];

long long e(long long x){
    long long ans=0;
    while(x>0){
        if(x%2==1){
            ans++;
        }
        x/=2;
    }
    return ans;
}

bool cmp(long long a, long long b){
    return a>b;
}

bool cmp2(long long a, long long b){
    int x=e(a), y=e(b);
    return x > y;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, cmp);
    int ans=a[1];
    for(int i=2; i<=m; i++){
        ans=ans & a[i];
    }
    cout << ans;
    return 0;
}

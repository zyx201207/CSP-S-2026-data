#include<bits/stdc++.h>
using namespace std;
//long long maxn = -1;
long long arr[500000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+n+1,greater<int>());
    long long ans = arr[1];
    for(int i = 2;i <= m;i++){
        ans &= arr[i];
    }
    cout << ans << '\n';
    return 0;
}


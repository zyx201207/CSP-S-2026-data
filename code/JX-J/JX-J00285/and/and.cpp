#include<bits/stdc++.h>
using namespace std;
long long n , m , ans , sum;
long long a[100010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a , a + n);
    ans = a[n - m];
    cout << ans;
return 0;
}


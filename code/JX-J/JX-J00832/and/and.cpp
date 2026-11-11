#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[20005];
bool cmp(long long x, long long y){
    return x > y;
}
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    long long ans = -1;
    for(int i = 1;i <= n - m + 1;i++){
        long long temp = a[i];
        for(int j = i;j<= m + i - 1;j++){
            temp = temp & a[j];
        }
        ans = max(ans, temp);
    }


    cout << ans;
    return 0;
}

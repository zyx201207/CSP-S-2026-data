#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5+5;

int n;
ll m;
ll a[N];
int ans = 1;
int l = 0;
ll sum =0 ;


int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum+=(i-l) * (a[i]-a[i-1]);
        while(sum > m && l<i){
            sum -= (a[i]-a[l]);
            l++;
        }
        ans = max(ans,i-l+1);
    }
    cout << ans;

    return 0;
}

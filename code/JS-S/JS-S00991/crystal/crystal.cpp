#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],ans[500005],cnt[500005],sum,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+1+n);
    a[0] = a[1];
    for (int i = 1;i <= n;i++){
        ans[i] = ans[i-1]+1;
        cnt[i] = cnt[i-1]+(a[i]-a[i-1])*ans[i-1];
        int k = i-ans[i]+1;
        while(cnt[i] > m){
            ans[i] -= 1;
            cnt[i] -= a[i]-a[k];
            k += 1;
        }
        sum = max(sum,ans[i]);
    }
    cout << sum;
    return 0;
}

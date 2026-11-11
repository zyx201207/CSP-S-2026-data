#include <iostream>
#include <algorithm>
#define mas 500010
#define int long long
using namespace std;

int n, m;
int a[mas], cf[mas], s[mas];

int solve(){
    int l, ans, sum, r=2;
    l=1; ans=0; sum=0;
    while (a[r]==a[r+1]) r++;
    for (;r<=n;r++){
        if (a[r]!=a[l]) sum+=(r-l)*(a[r]-a[r-1]);
        while (a[r]==a[r+1]) {r++;}
        // for (int i=l;i<r;i++)
        //     sum+=(a[r]-a[i]);
        while (sum>m){
            sum-=a[r]-a[l];
            l++;
        }
        // cout << l << " " << r << ":" << sum << endl;
        ans=max(ans, r-l+1);
    }
    return ans;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    // for (int i=1;i<n;i++){
    //     cf[i]=a[i+1]-a[i];
    //     cout << cf[i] << " ";
    // }
    // cout << endl;


    
    cout << solve() << endl;

    return 0;
}
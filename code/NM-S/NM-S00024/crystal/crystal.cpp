#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        int j = i,sum=0,x=m;
        while(x>a[j] && j>=1){
            sum++;
            x -= a[i]-a[j];
            j--;
        }
        ans = max(ans,sum);
    }
    cout << ans;
    return 0;
}

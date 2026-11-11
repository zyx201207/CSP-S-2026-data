#include <iostream>
#include <cstdio>
using namespace std;
int n,m,maxn;
int a[200005],f[200005],maxv;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        maxv = max(maxv,a[i]);
    }
    f[1] = a[1];
    maxn = a[1];
    if(m==1){
        cout << maxv;
        return 0;
    }
    if(m == 2){
        int ans = 0;;
        for(int i = 1;i <=n;i++){
            for(int j = i+1;j <= n;j++){
                ans = max(ans,a[i]&a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if(m==n){
        int ans = a[1];
        for(int i = 2;i <=n;i++){
            ans = a[i]&ans;
        }
        cout << ans;
        return 0;
    }
    for(int i = 2;i <= n;i++){
        maxn = max(maxn,a[i]);
        for(int j = m;j >= 2;j--){
            f[j] = max(f[j],f[j - 1]&a[i]);
            //cout << f[j] << ' ';
        }
        f[1] = maxn;
        //cout << f[1] << endl;
    }
    cout << f[m];
    return 0;
}

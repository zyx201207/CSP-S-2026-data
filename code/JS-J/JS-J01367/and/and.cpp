#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int maxx = -0x3f3f3f3f;
    if(m == 1){
        for(int i = 1;i<=n;i++){
            maxx = max(a[i],maxx);
        }
        cout<<maxx;
        return 0;
    }
    if(m == n){
        int ans = a[1];
        for(int i = 2;i<=n;i++){
            ans = ans&a[i];
        }
    }
    if(m == 2){
        int ans = -0x3f3f3f3f;
        for(int i = 1;i<n;i++){
            for(int j = i+1;j<=n;j++){
                ans = max(a[i]&a[j],ans);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m == n-1){
        sort(a+1,a+n+1);
        int ans = a[n];
        for(int i = n-1;i>1;i--){
            ans = ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    int ok = 1;
    for(int i = 1;i<=n;i++){
        if(a[i] != i-1)ok = 0;
    }
    if(ok){
        sort(a+1,a+n+1);
        int ans = a[n];
        for(int i = n-1;i>=n-m;i--){
            ans = ans&a[i];
        }
        cout<<ans;
    }
    sort(a+1,a+n+1);
    int ans = a[n];
    for(int i = n-1;i>=n-m;i--){
        ans = ans&a[i];
    }
    cout<<ans;
    return 0;
}

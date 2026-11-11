#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
long long dg(int b,int c){
    if(c == n){
        return a[b];
    }
    long long ans = 0;
    for(int i = b;i<=n;i++){
        ans = max(ans,dg(i+1,c+1));
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(m == 1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m == n){
        for(int i = n;i>1;i--){
            a[i-1] = (a[i-1] & a[i]);
        }
        cout<<a[1];
        return 0;
    }
    if(m == 2){
        long long ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                ans = max((a[i]&a[j]),ans);
            }
        }
        cout<<ans;
        return 0;
    }
    cout<<dg(1,1);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int const N = 2e5+20;

int n,m;
long long ans,a[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    if(m == 1){
        ans = 0;
    }else if(m==2){
        for(int i = 1;i < n;i++){
            for(int j = i+1;j <= n;j++){
                long long x = (a[i]&a[j]);
                ans = max(ans,x);
            }
        }
    }else if(m==n){
        ans = a[1];
        for(int i = 2;i <= n;i++){
            ans = (ans&a[i]);
        }
    }else if(m==(n-1)){
        ans = a[2];
        for(int i = 3;i <= n;i++){
            ans = (ans&a[i]);
        }
        for(int i = 2;i <= n;i++){
            long long s = a[1];
            for(int j = 2;j <= n;j++){
                if(i==j) continue;
                s = (s&a[j]);
            }
            ans = max(ans,s);
        }
    }
    cout<<ans;
    return 0;
}

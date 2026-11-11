#include <bits/stdc++.h>
using namespace std;
int a[214514],n,m,mx=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout << mx;
    }else if(m==n){
        mx=a[1];
        for(int i=2;i<=n;i++){
            mx&=a[i];
        }
        cout << mx;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,(a[i]&a[j]));
            }
        }
        cout << mx;
    }else if(n<=22){
        for(int i=0;i<(1<<n);i++){
            int cnt=0,ans=INT_MAX;
            for(int j=0;j<n;j++){
                cnt+=(i>>j&1);
                if(i>>j&1)ans&=a[j+1];
            }
            if(cnt==m)mx=max(mx,ans);
        }
        cout << mx;
    }else{
        cout << 0x3f3f3f3f;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>ans){
                    ans=(a[i]&a[j]);
                }
            }
        }
    }
    else if(m==1){
        sort(a+1,a+n+1);
        ans=a[n];
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            ans=(ans&a[i]);
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,(ans&a[i]));
        }
    }
    else{
        sort(a+1,a+n+1);
        ans=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            ans=(ans&a[i]);
        }
    }
    cout<<ans;
    return 0;
}

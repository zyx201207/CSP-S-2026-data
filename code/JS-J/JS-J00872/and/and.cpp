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
    if(m==1){
        sort(a+1,a+1+n);
        ans=a[n];
        m--;
        for(int i=n-1;i>=1;i--){
            if(m==0) break;
            ans=(ans&a[i]);
            m--;
        }
        cout<<ans;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(a[i]&ans);
        }
        cout<<ans;
    }
    else{
        sort(a+1,a+1+n);
        ans=a[n];
        m--;
        for(int i=n-1;i>=1;i--){
            if(m==0) break;
            ans=(ans&a[i]);
            m--;
        }
        cout<<ans;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long m,n,a[200005],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[i];
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++)ans=max(ans,a[j]&a[k]);
            }
        }
    }
    cout<<ans;
    return 0;
}

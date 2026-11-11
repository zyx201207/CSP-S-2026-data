#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)ans=(ans&a[i]);
        cout<<ans;
        return 0;
    }
    if(m==1){
        ans=-1;
        for(int i=1;i<=n;i++){
            if(a[i]>ans)ans=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        ans=a[1];
        for(int i=2;i<n;i++)ans=(ans&a[i]);
        cout<<ans;
        return 0;
    }
    else{
        int mx=-1,nx=-1;
        for(int i=1;i<=n;i++){
            if(a[i]>mx)mx=a[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]==mx){
                a[i]=-1;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]>nx)nx=a[i];
        }
        cout<<(mx&nx);
        return 0;
    }
    return 0;
}

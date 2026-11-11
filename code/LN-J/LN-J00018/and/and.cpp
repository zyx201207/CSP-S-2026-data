#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[1];return 0;
    }
    if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;return 0;
    }
    if(m==2){
        long long ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>ans){
                    ans=a[i]&a[j];
                }
            }
        }
        cout<<ans;return 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[20022];
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                long long cnt=a[i]&a[j];
                ans=max(ans,cnt);
            }
        }
        cout<<ans;
    }
    return 0;
}

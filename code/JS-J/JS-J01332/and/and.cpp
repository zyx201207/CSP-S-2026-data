#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]&(1<<i)){
                cnt++;
            }
        }
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if(a[j]&(1<<i)){
                    a[j]%=(1<<i);
                }
                else a[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}

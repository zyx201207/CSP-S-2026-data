#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    //
    cin>>n>>m;
    long long maxn=-1;
    for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
    long long ans=0;
    if(n==m){
        ans=a[1];
        for(int i=2;i<=n;i++)ans=ans&a[1];
    }
    if(m==1)ans=maxn;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)ans=max(ans,a[i]&a[j]);
            }
        }
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(i!=j&&i!=k&&j!=k)ans=max(ans,a[i]&a[j]&a[k]);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

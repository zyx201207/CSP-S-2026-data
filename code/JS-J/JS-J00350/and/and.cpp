#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int m,n,a[N],ans,lef[N],rht[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
    }
    if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++) ans=ans&a[i];
    }
    if(m==2){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    if(m==n-1){
        lef[1]=a[1];
        rht[n]=a[n];
        for(int i=2;i<=n;i++) lef[i]=lef[i-1]&a[i];
        for(int i=n-1;i>=1;i++) rht[i]=rht[i+1]&a[i];
        for(int i=2;i<=n-1;i++){
            ans=max(ans,rht[i+1]&lef[i-1]);
        }
    }
    cout<<ans;
    return 0;
}

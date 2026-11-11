#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }cout<<ans;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }cout<<maxn;
    }else if(m==n-1){
        ans=a[2];
        for(int i=3;i<=n;i++){
            ans&=a[i];
        }cout<<max(ans,a[1]);
    }else{
        cout<<a[n-m];
    }
    return 0;
}

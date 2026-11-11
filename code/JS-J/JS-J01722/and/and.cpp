#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(m==n-1){
        ans=a[1];
        for(int i=2;i<=n-1;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }else{
        ans=a[1];
        for(int i=2;i<=m;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    return 0;
}

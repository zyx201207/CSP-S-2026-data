#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int sum[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n-1){
        sum[1]=a[1];
        int ans=0;
        for(int i=2;i<=n;i++){
            sum[i]=sum[i-1]&a[i];
        }
        for(int i=1;i<=n;i++){
            ans=max(sum[n]&a[i],ans);
        }
        cout<<ans;
    }
    return 0;
}
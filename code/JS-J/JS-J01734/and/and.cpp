#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,ans=1,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<0;
        return 0;
    }
    else if(m==n){
        ans=(a[1] & a[2]);
        for(int i=3;i<=n;i++){
            ans=(ans & a[i]);
        }
        cout<<ans;
        return 0;
    }
    else if(m==2){
        int Max=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i] & a[j])>Max){
                    Max=(a[i] & a[j]);
                }
            }
        }
        cout<<Max;
        return 0;
    }
    else{
        sort(a+1,a+n+1);
        ans=a[n] & a[n-1];
        for(int i=n;i>n-m;i--){
            ans=(ans & a[i]);

        }
        cout<<ans;
    }
    return 0;
}

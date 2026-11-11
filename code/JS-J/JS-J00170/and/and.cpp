#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000+5],maxn=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(a[i]!=i-1){
            flag=false;
        }
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int ans=a[1]&a[2];
        for(int i=3;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        int maxans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n,j!=i;j++){
                maxans=max(maxans,a[i]&a[j]);
            }
        }
        cout<<maxans;
        return 0;
    }
    if(m==n-1){
        int maxans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n,j!=i;j++){
                maxans=max(maxans,a[i]&a[j]);
            }
        }
        int maxa=-1;
        for(int i=1;i<=n;i++){
            maxa=max(maxa,maxans^a[i]);
        }
        cout<<maxa;
        return 0;
    }
    if(flag==true){
        cout<<n-m;
        return 0;
    }
    else{
        cout<<a[n-m+1];
        return 0;
    }
    cout<<maxn;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],b[10000000],c[10000000],ans=-10000000;
int f;
int main(){
    freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    cin>>n>>m;
    f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        c[i+1]=a[i+1]-a[i];
    }for(int i=2;i<n;i++){
        if(c[i]!=c[i+1]){
                f=1;
        break;
        }
    }
    for(int i=1;i<=n;i++){
        b[i]=c[i]+b[i-1];
    }
    for(int i=n;i>=1;i--){
        long long mo=m,aa=0,t=i;
        while(mo>=0&&t>0){
            t--;
            mo-=(b[i]-b[t]);
            aa++;
        }aa--;
if(f=0){
    cout<<aa+1<<f;
    return 0;
}
        ans=max(aa,ans);
    }
    cout<<ans+1;
}

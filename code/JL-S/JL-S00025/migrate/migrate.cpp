#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long t;
    cin>>t>>t;
    while(t--){
        long long n,d,x,y;
        cin>>n>>d;
        cin>>y;
        for(int i=1;i<n;i++){
            cin>>x;
            a[i]=x-y;
            y=x;
        }
        long long ans=0;
        for(int r=1;r<n;r++)
            for(int l=0;l<r;l++){
                long long cnd=0;
                for(int i=l+2;i<r;i++){
                    if(a[i]>d){
                        cnd=-1e9;
                    }
                    if(a[i-1]+a[i]<=d && a[i]+a[i+1]<=d && a[i-1]+a[i]+a[i+1]>d){
                        cnd++;
                    }
                }
                if(a[l+1]>d || a[r]) cnd=-1e9;
                if(cnd==1) ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}

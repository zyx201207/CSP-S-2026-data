#include<bits/stdc++.h>
using namespace std;
#define int long long
int e[35],a[1000005],u[1000005],p[35];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int x,y,t=0,ans=0;
    cin>>x>>y;
    p[1]=1;
    for(int i=2;i<=32;i++){
        p[i]=p[i-1]*2;
    }
    for(int i=1;i<=x;i++){
        u[i]=1;
        cin>>a[i];
        int k=a[i];
        for(int i=1;k;i++){
            t=max(t,i);
            e[i]+=k%2;
            k/=2;
        }
    }
    for(int i=t;i;i--){
        if(e[i]>=y){
            ans+=p[i];
            for(int j=1;j<=x;j++){
                if(u[j]&&a[j]/p[i]%2!=1){
                    for(int k=1;a[j];k++){
                        e[k]-=a[j]%2;
                        a[j]/=2;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

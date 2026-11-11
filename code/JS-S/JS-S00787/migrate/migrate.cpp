#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[100005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int mi=1000005,ma=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>=2){
                mi=min(mi,a[i]-a[i-1]);
            }
        }
        ma=a[n]-a[1];
        if(d<=mi||d>=ma){
            cout<<0<<endl;
            continue;
        }
        mi=10000005;ma=0;
        int ans=0;
        for(int i=1;i+3<=n;i++){
            mi=min(a[i+3]-a[i+1],min(mi,a[i+2]-a[i]));
            if(d>=mi){
                ans++;
            }
        }
        cout<<ans;
        memset(a,0,sizeof(a));
    }
    return 0;
}



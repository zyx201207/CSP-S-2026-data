#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005];
ll c,t,n,d,ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n==1){
            cout<<0<<endl;continue;
        }
        bool A=1,B=0,C=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>2&&2*a[i-1]!=a[i-2]+a[i]) A=0;
        }
        if(a[n]-a[1]<=2*d) B=1;
        if(a[n]-a[1]<=10*d) C=1;
        if(A){
            ll minu=a[2]-a[1];
            if(d==minu) ans=0;
            else{
                int k=d/minu;
                ans=max(0ll,n-(2*k-1));
            }
            cout<<ans<<endl;continue;
        }
        if(B){
            ll st=a[n]-d,en=a[1]+d,cnt=0;
            for(int i=1;i<=n;i++){
                if(st<=a[i]&&a[i]<=en) cnt++;
            }
            cout<<(cnt==2)<<endl;continue;
        }
        if(C){
            ll j=1;
            for(int i=1;i<=n;i++){
                while(j<n&&a[j]-a[i]<2*d) j++;
                ll st=a[j]-d,en=a[i]+d,cnt=0;
                for(int k=1;k<=n;k++){
                    if(st<=a[k]&&a[k]<=en) cnt++;
                }
                if(cnt==2) ans++;
                if(j==n) break;
            }
            cout<<ans<<endl;continue;
        }
    }
    return 0;
}

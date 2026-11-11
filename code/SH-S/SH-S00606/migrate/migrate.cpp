#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int a[2000010];
    int x,n,d;
    while(t--){
        int ans=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        x=(a[n]-a[1])/(n-1);
        int l=d/x;
        if(l==0) cout<<0<<endl;
        else{
            for(int i=l+1;i<=min(l+l-1,n-1);i++){
                for(int j=n-1;j>=n-i;j--){
                    ans*=j;
                }
                for(int j=1;j<=i;j++){
                    ans/=j;s
                }
            }
            cout<<ans<<endl;
        }
    }
}

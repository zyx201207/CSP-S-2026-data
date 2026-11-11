#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int a[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
            int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    int l=i;int x=1;int lu=i;
                    for(int k=i+1;k<=j;k++){
                        if(k-l>d){
                              int xx=0;  for(int u=lu+1;u<k-1;u++) if(a[u]-a[lu]<=d&&a[k-1]-a[u]<=d) xx++;
                            x*=(k-l);
                            l=k-1;
                            lu=l;
                        }
                    }
                if(x==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}

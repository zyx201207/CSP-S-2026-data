#include<bits/stdc++.h>
using namespace std;
#define int long long
int r,t,n,d,ans;
int a[2000005],vis[2000005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>r>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int k=2;k<=n/d+1;k++){
                for(int j=i+d*(k-1)+1;j<i+d*k;j++){
                    if(j>n) break;
                    if(a[j]<=a[i]+d*k){
                        for(int l=i+d*(k-1);l>=j-d;l--){
                            if(a[l]>=a[j]-d) vis[j]++;
                            else break;
                        }
                        if(vis[j]==2){
                            ans++;
                        }
                    }else{
                        break;
                    }
                }
                for(int j=1;j<=n;j++) vis[j]=k-1;
            }
            for(int j=1;j<=n;j++) vis[j]=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],f[1000005],dp[1000005],u,v,c,ans;
int l[1000005],r[1000005],T;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12||c==0){
            m=m/(a[2]-a[1]);
            if(m<=1) {
                cout<<0<<'\n';
                continue;
            }
            dp[1]=1;
            f[1]=1;
            for(int i=2;i<=n;i++){
                dp[i]=dp[max(i-m,1ll)]+1;
                f[i]=f[max(i-m,1ll)];
                if(max(i-m,1ll)+1<i&&dp[max(i-m,1ll)+1]+1==dp[i]){
                    f[i]+=f[max(i-m,1ll)+1];
                }
                if(max(i-m,1ll)+2<i&&dp[max(i-m,1ll)+2]+1==dp[i]){
                    f[i]+=f[max(i-m,1ll)+2];
                }
                if(f[i]==2) {
                    ans+=n-i+1;
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        int k=1;
        for(int i=1;i<=n;i++){
            while(a[i]-a[k]>m) k++;
            l[i]=k;
        }
        a[n+1]=4e18;
        k=1;
        for(int i=1;i<=n;i++){
            while(a[k+1]-a[i]<=m) k++;
            r[i]=k;
        }
        for(int i=1;i<=n;i++){
            f[r[i]]=1;
            dp[r[i]]=1;
            for(int j=r[i]+1;j<=n;j++){
                if(l[j]==j) break;
                dp[j]=dp[max(l[j],r[i])]+1;
                f[j]=f[max(l[j],r[i])];
                //cout<<dp[j]<<' ';
                if(f[j]>2) break;
                if(l[j]+1<j&&dp[max(l[j]+1,r[i])]+1==dp[j]){
                    f[j]+=f[max(l[j]+1,r[i])];
                }
                if(l[j]+2<j&&dp[max(l[j]+2,r[i])]+1==dp[j]){
                    f[j]+=f[max(l[j]+2,r[i])];
                }
                if(f[j]==2) {
                    // cout<<i<<' '<<j<<'\n';
                    ans++;
                }
            }//cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
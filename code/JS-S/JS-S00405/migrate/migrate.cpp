#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x[2000005];
int f[5005][5005];
void solve(){
    int n;
    ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e9;
        }
    }
    int l=1,r=1;
    while(x[r+1]-x[l]<=d){
        r++;
    }
    for(int i=2;i<=r;i++)f[l][i]=1;
    f[1][1]=0;
    for(l=2;l<=n;l++){
        while(r<n&&x[r+1]-x[l]<=d)r++;
        for(int j=l+1;j<=r;j++){
            f[l][j]=1;
        }
        f[l][l]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cnt=0;
            for(int k=i+1;k<j;k++){
                if(f[i][k]+f[k][j]==f[i][j]){
                    cnt++;
                }
            }
            if(cnt==2)ans++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}

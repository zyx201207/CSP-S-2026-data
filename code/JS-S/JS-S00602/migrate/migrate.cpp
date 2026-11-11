#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
ll a[N][N];
ll cnt[N][N],x[N];
void solve(){
    ll n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[i][j]=0;
            cnt[i][j]=0;
        }
        x[i]=0;
    }
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<n;i++){
        int j=i+1;
        while(x[j]-x[i]<=d&&j<=n){
            a[i][j]=1;
            j++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][j]) continue;
            int s=lower_bound(x+1,x+n+1,x[j]-d)-x;
            if(s!=j)    a[i][j]=a[i][s]+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cerr<<a[i][j]<<" ";
        }
        cerr<<"\n";
    }
    cerr<<"\n";
    cerr<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<=j-1;k++){
                if(a[i][k]==0||a[k][j]==0) continue; 
                if(a[i][j]==a[i][k]+a[k][j]){
                    cnt[i][j]++;
                } 
                if(cnt[i][j]>2) break;
            }
        }
    }
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cerr<<cnt[i][j]<<" ";
        }
        cerr<<"\n";
        }
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(cnt[i][j]==2){
                cerr<<i<<" "<<j<<"\n";
                ans++;
            } 
        }
    cout<<ans<<"\n";
}
void solve2(){
    
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        if(c==11||c==12){

        }
        else if(c==13||c==14){
            solve2();
        }else{
            solve();
        }
    }
}
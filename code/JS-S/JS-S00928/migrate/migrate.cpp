#include<bits/stdc++.h>
using namespace std;
long long ans,c,n,d,a[5000005];
long long mn[5000005],t,turn[5000005];
void f(long long x,long long r){
    for(long long i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d){
            long long w=r+1;
            if(w<mn[i]){
                mn[i]=w;
                turn[i]=1;
            }
            else if(w==mn[i]){
                turn[i]++;
            }
            f(i,w);
        }
    }
}
int main(){
    freopen("./migrate.in","r",stdin);
    freopen("./migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        if(c>10){
            cout<<0;
            continue;
        }
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                mn[j]=10000000;
                turn[j]=0;
            }
            f(i,0);
            for(long long j=1;j<=n;j++){
                if(turn[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

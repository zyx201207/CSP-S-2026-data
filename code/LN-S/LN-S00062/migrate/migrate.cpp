#include<bits/stdc++.h>
using namespace std;
const int N=2e6+8;
long long n,d,a[N];

void solve(){
    cin>>n>>d;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        int cnt1=0,cnt2=0,cnt3=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(abs(a[i]-a[j])==abs(a[i]-a[k])&&(abs(a[i]-a[j])<=d)&&(abs(a[i]-a[k])<=d))cnt1++;
                if(abs(a[i]-a[j])==abs(a[j]-a[k])&&(abs(a[i]-a[j])<=d)&&(abs(a[j]-a[k])<=d))cnt2++;
                if(abs(a[k]-a[j])==abs(a[i]-a[k])&&(abs(a[k]-a[j])<=d)&&(abs(a[i]-a[k])<=d))cnt3++;
            }
        }
        if(cnt1==2){
           ans++;
         }if(cnt2==2)ans++;
         if(cnt3==2)ans++;
    }cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;cin>>c>>t;
    while(t--){
        solve();
    }
}

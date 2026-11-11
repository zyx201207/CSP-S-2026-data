#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,m;
int a[N],b[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0;
    for(int j=30;j>=0;j--){
        int cnt=0,res=0;
        for(int i=1;i<=n;i++) if(!b[i]) cnt+=((a[i]&(1ll<<j))==0),res++;
        if(res-cnt>=m){
            for(int i=1;i<=n;i++) if(!b[i]) if((a[i]&(1ll<<j))==0) b[i]=1;
            ans+=(1ll<<j);
//            cout<<j<<"\n";
        }
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--) solve();
}

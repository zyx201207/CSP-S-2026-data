#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sp ' '
#define int long long
int n,k;
int a[2000005];
#define d(i,j) a[j]-a[i-1]
int chk(int l,int r,int x){
    int cnt=0;
    for(int i=l;i+x<=r+1;i++){
        if(d(i,i+x-1)<=k)cnt++;
    }
    return cnt;
}
void mian(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ll=1,rr=0,ans=0;
    for(int i=1;i<=n;i++){
        if(d(i,i+1)>k||i==n){
            rr=i;
            int l=2,r=rr-ll+1,mid,aa=0,ab=0;
            while(l<=r){
                mid=(l+r)/2;
                int x=0;x=chk(ll,rr,mid);
                if(x){aa=mid;ab=x;l=mid+1;}
                else r=mid-1;
            }
            cout<<ll<<sp<<rr<<sp<<aa<<sp<<ab<<endl;
            ll=i+1;
            ans+=ab*(ab-1)/2;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    #ifndef LOCAL
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        mian();
    }
    return 0;
}
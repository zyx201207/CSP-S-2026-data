#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5;
int n,a[N+5],la,ra,l,ll,rr,lp,rp,ans;
char c[N+5],lc,rc;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        l+=a[i];
    }
    la=a[1],ra=a[n],lc=c[1],rc=c[n],lp=1,rp=n;
    while(ll<l/2 || rr<l/2){
        if(la+ll>=l/2){
            la=l/2-ll;
        }else if(ra+rr>=l/2){
            ra=l/2-rr;
        }
        int cnt=min(la,ra);
        if(lc!=rc){
            ans+=cnt;
        }
        la-=cnt,ra-=cnt,ll+=cnt,rr+=cnt;
        a[lp]-=cnt,a[rp]-=cnt;
        if(!la){
            la=a[++lp],lc=c[lp];
        }
        if(!ra){
            ra=a[--rp],rc=c[rp];
        }
    }
    cout << ans;
    return 0;
}
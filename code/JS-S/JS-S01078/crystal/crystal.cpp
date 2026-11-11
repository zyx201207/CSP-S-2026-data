#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
const ll MXN=200005;
ll n,m;
ll a[500005];
ll l=1,r;
ll sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //csp_s = Contest of SleePer - Sleeping
    //after 45 min sleeping , stoneshadow the n3wb13 know the real answer is to l-r-mid(er fen) . soon he get the answer.
    cin>>n>>m;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    //for(int i=1;i<=n;i++){cout<<sum[i]<<' ';}
    //ll q;cin>>q;while(q--){int A,B;cin>>A>>B;cout<<sum[B]-sum[A-1]-(A-1)*(a[B]-a[A-1])<<endl;}//caculate a[A] to a[B]

    ll mid=l+r;mid/=2;
    while(l+1<r){
            //cout<<1;
        mid=(l+r)/2;
        bool f=0;
        for(int i=mid;i<=n;i++){
            int j=i-mid+1;
            ll dis=sum[i]-sum[j-1]-(j-1)*(a[i]-a[j-1]);
            if(dis<=m){
                f=1;break;
            }
        }
        if(f==1)l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m;
ll a[N]={0};
ll diff[N]={0};
ll x=0;
ll pos=0;
ll cnt=0;
ll bj;
ll tot=0;
bool f=0;
bool ff=0;
ll maxn=-0x3f3f3f3f;
ll y=0;
ll ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++){
        if(a[i+1]-a[i]!=a[i+2]-a[i+1]){
            f=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            ff=1;
        }
    }
    if(f==0){
        ll tmp=a[2]-a[1];
        ll js=m/tmp;
        while(x<=js){
            tot++;
            y++;
            x+=y;
        }
        cout<<tot<<endl;
        return 0;
    }else{
        if(ff==0){
            ll js=m;
            while(x<=js){
                tot++;
                y++;
                x+=y;
            }
            cout<<tot<<endl;
            return 0;
        }else{
            for(int i=2;i<=n;i++){
                for(int j=1;j<=i-1;j++){
                    pos+=a[i]-a[j];
                }
                if(pos>m){
                    maxn=max(maxn,(ll)i-1);
                    continue;
                }
                pos=0;
            }
            cout<<maxn<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+5;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    int f=1;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i!=1){
            if(a[i]-a[i-1]!=a[2]-a[1]){
                f=0;
            }
        }
    }
    if(f){
        int c=abs(a[2]-a[1]);
        if(c==0){
            cout<<0;
        }
        else{
            cout<<min(ll(n),m/c+1);
        }
        return 0;
    }
    sort(a+1,a+n+1);
    int maxn=1;
    for(int i=1;i<=n;i++){
        ll x=m;
        int cnt=1;
        for(int j=i-1;j>=1;j--){
            if(x-(a[i]-a[j])<0){
                break;
            }
            else{
                cnt++;
                x-=(a[i]-a[j]);
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
ll dp_last,dp_now;
ll n,m,a[N],ansmax=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp_last=m;
    dp_now=m;
    sort(a+1,a+1+n);
    ll j=1;
    for(ll i=2;i<=n;i++){
        dp_now=dp_last-(a[i]-a[i-1])*(i-j);
        if(dp_now<0){
            while(dp_now<0){
                dp_now+=(a[i]-a[j]);
                j++;
            }
        }
        ansmax=max(ansmax,(i-j+1));
        swap(dp_last,dp_now);
    }
    cout<<ansmax;
    return 0;
}

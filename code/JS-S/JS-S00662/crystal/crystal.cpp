#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[505050];
ll d[505050];
ll ans=0;
ll i=1,j=1;
ll del=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        d[i-1]=a[i]-a[i-1];
    }
    d[n]=2e12+9;
    i=1;
    j=1;
    del=0;
    while(i<=n){
        ans=max(ans,j-i+1);
        //cout<<i<<" "<<j<<" "<<del<<'\n';
        //if(del<0) cout<<"sdfsdfsa";
        if(j==n) break;
        if(d[j]*(j-i+1)+del>m){
            if(i==n) break;
            i++;
            j=max(i,j);
            del-=a[j]-a[i];
            ans=max(ans,j-i+1);
        }
        else{
            del+=d[j]*(j-i+1);
            j++;
            ans=max(ans,j-i+1);
        }
    }
    ans=min(n,ans);
    cout<<ans<<'\n';
    return 0;
}
//g++ crystal.cpp -o crystal -std=c++14 -O2
// ./crystal
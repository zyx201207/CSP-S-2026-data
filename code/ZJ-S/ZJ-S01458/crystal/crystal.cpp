#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll M=1e12;
int n,ans=1;
ll m,a[N];
int main(){
     freopen("crystal.in","r",stdin);
     freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    int i=1,j=1;
    ll sum=0;
    while(j<=n){
        sum+=1ll*(j-i+1)*(a[j+1]-a[j]);
        j+=1;
        while(i<j&&sum>m){
            sum-=a[j]-a[i];
            i+=1;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    ll sum=0;
    int ans=0;
    for(int i=0,j=0;i<n;++i){
        while((i-j)*a[i]-sum>m){
            sum-=a[j];
            ++j;
        }
        ans=max(ans,i-j+1);
        sum+=a[i];
    }
    cout<<ans<<endl;
}

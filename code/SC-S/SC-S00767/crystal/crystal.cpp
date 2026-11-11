#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+500;
mt19937 rad((0xC3+0xC5)>>1);
int n;ll m,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    shuffle(a+1,a+n+1,rad),sort(a+1,a+n+1);
    int j=1,ans=1;ll res=0;
    for(int i=2;i<=n;i++){
        res+=(a[i]-a[i-1])*(i-j);
        for(;res>m;j++)res-=a[i]-a[j];
        ans=max(ans,i-j+1);
    }cout<<ans<<"\n";
    cout.flush();
    return 0;
}
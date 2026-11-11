#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
using ll=long long;
using ull=unsigned long long;

ll n,m;
ll a[maxn];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ull tmp=0;
    int ans=1;
    for(int i=1,j=2;j<=n;j++){
        tmp+=(j-i)*(a[j]-a[j-1]);
        while(tmp>m&&i<=j){
            tmp-=(a[j]-a[i]);
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    a[n+1]=a[n];
    int l=n;
    for(int r=n;r>=1&&l>=1;--r){
        m+=(r-l+1)*(a[r+1]-a[r]);
        while(m>=0&&l>0){
            l--;
            if(l>0)m-=(a[r]-a[l]);
            else m=-1;
        }
        ans=max(ans,r-l);
    }
    cout<<ans;
    return 0;
}
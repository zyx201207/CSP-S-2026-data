#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,a[500010],ans,op;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    r=1,l=1,ans=1;
    while(r<n){
        r++;
        op=op+(r-l)*(a[r]-a[r-1]);
        while(op>m){
            l++;
            op=op-(a[r]-a[l-1]);
        }
        ans=max(ans,(r-l+1));
    }
    cout<<ans;
    return 0;
}

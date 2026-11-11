#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long tot=0;
    int ans=0;
    for(int r=1,l=1;r<=n;r++,tot+=(a[r]-a[r-1])*(r-l)){
        while(tot>m){
            tot-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
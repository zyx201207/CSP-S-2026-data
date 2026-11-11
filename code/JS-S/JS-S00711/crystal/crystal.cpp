#include<bits/stdc++.h>
using namespace std;

int n;
long long k,x[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>x[i];
    }
    sort(x+1,x+n+1);
    int ans=1;
    long long need=0;
    for(int l=1,r=2;r<=n;++r){
        need+=(x[r]-x[r-1])*(r-l);
        while(need>k){
            need-=x[r]-x[l];
            ++l;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}

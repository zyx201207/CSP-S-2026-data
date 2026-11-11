#include <bits/stdc++.h>
using namespace std;
const int MN=5e5+5;
long long a[MN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0,t=0;
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    int l=0,r=1;
    while(l<n){
        if(t>m||r==n){
            t-=a[r-1]-a[l++];
        }else{
            if(r-l>ans) ans=r-l;
            t+=(a[r]-a[r-1])*(r-l);
            ++r;
        }
    }
    cout<<ans;
    return 0;
}
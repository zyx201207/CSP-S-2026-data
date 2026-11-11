#include<bits/stdc++.h>
#define For(i,j,k) for(auto i=(j);i<=(k);i++)
#define dFor(i,j,k) for(auto i=(j);i>=(k);i--)
using namespace std;
#define MAXN 500005
long long n,m,a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    For(i,1,n){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    int l=1;
    long long now=0;
    For(r,1,n){
        now+=(a[r]-a[r-1])*(r-l);
        while(now>m){
            now-=(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
/*
g++ -O2 -std=c++14 -Wall -Wextra -Wshadow -o crystal crystal.cpp
*/
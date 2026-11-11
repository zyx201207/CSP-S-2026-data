#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],hd=1,tl=1,k,s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        tl++;
        k+=(tl-hd)*(a[tl]-a[tl-1]);
        while(k>m){
            k-=(a[tl]-a[hd]);
            hd++;
        }
        s=max(s,tl-hd+1);
    }cout<<s;
    return 0;
}

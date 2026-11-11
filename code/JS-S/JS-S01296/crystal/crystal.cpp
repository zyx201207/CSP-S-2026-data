#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
long long b[100005];
int maxx=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    int l,r;
    l=r=1;
    long long wl=0;
    while(r<n){
        if(r<n&&wl+b[r]*(r-l+1)<=m){
            wl+=b[r]*(r-l+1);
            r++;
        }else{
            maxx=max(maxx,r-l+1);
            wl-=(a[r]-a[l]);
            l++;
        }
    }
    maxx=max(maxx,r-l+1);
    cout<<maxx;
    return 0;
}


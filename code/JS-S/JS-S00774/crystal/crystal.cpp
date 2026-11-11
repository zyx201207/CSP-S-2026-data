#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll a[5*100009],n;
ull m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1;
    ull mcur=0;
    ll ans=1;
    for(int r=2;r<=n;r++){
        mcur=mcur+(r-l)*(a[r]-a[r-1]);
        while(l<r&&mcur>m){
            mcur=mcur-(a[r]-a[l]);
            l++;
        }
        if(ans<(r-l+1)){
            ans=r-l+1;
        }
    }
    cout<<ans;
    return 0;
}

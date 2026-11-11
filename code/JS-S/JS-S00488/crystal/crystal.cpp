#include<bits/stdc++.h>
using namespace std;
#define ull long long
ull a[500005],qz[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull n,m;
    cin>>n>>m;

    for(ull i=1;i<=n;++i){
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    for(ull i=1;i<=n;++i){
        qz[i]=qz[i-1]+a[i];
    }

    ull ans=0;
    ull oo=0;
    for(ull i=1;i<=n;++i){
        ull l=i,r=n;
        ull mid;
        ull t=1;
        while(1){

            if(l>=r){
                break;
            }
            mid=(l+r)/2;
            if(a[mid]*(mid-i+1)<=qz[mid]-qz[i-1]+m){
                oo=mid;
                l=(l+r+1)/2;
            }
            else{
                r=(l+r)/2;
            }
        }
        if(oo-i+1>ans){
            ans=oo-i+1;
        }
    }
    cout<<ans;


    return 0;
}

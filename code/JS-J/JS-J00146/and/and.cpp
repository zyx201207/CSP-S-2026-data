#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[200005];
int mw[35];
void tmp(int a){
    int ws=0;
    while(a>0){
        if(a%2==1){
           mw[ws]++;
        }
        a/=2;
        ws++;
    }
}
signed main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tmp(a[i]);
    }
    int ans=0;
    for(int i=0;i<=30;i++){
        if(mw[i]>=2)ans+=pow(2,i);
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum=0;
ll n;
ll num=0;
ll a[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll ai;
        cin>>ai;
        char ci;
        cin>>ci;
        c[i]=ci;
        a[i]=ai;
        num+=ai;
    }
    int f=1,l=n,nf=1,nl=1;
    for(ll i=0;i<num;i++){
        if(nf>a[f]){
            f++;
            nf=1;
        }
        if(nl>a[l]){
            l--;
            nl=1;
        }
        if(c[f]!=c[l]){
            sum++;
        }
        nf++;
        nl++;
    }
    cout<<sum/2;
    return 0;
}


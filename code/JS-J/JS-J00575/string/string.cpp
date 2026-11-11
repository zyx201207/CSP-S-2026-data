#include <iostream>
#include <cstdio>
using namespace std;
#define ll unsigned long long
ll n,a[200003],ans=0,tot=0,m[200003];
char c[200003];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        tot+=a[i];
        m[i]=tot;
    }
    ll l=1,r=n,nl=1,nr=tot;
    while (l<r){
        if (c[l]!=c[r]) ans+=min(m[l]-nl+1ull,nr-m[r-1]);
        if (nr-m[r-1]<m[l]-nl+1){
            nl+=nr-m[r-1];nr=m[r-1];r--;
        }
        else if (nr-m[r-1]>m[l]-nl+1){
            nr-=m[l]-nl+1;nl=m[l]+1;l++;
        }
        else{
            nl=m[l]+1;nr=m[r-1];r--;l++;
        }
    }
    cout<<ans;
    return 0;
}

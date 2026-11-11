#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],nw,b[500005],k,mx,los;
int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        b[i]=a[i]-a[i-1];
    }
    for(int i=0;i<n;i++){
        k+=nw*b[i];
        while(k>m){
            k-=(a[i]-a[los]);
            los++;
            nw--;
        }
        nw++;
        mx=max(mx,nw);
    }
    cout<<mx;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    vector<pair<ll,char> >a(n);
    ll len=0;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        len+=a[i].first;
    }
    ll cnt=0;
    ll lin=0,rin=n-1;
    while(len>0){
        if(lin>=rin)break;
        ll l=min(a[lin].first,a[rin].first);
        if(a[lin].second!=a[rin].second)cnt+=l;
        a[lin].first-=l,a[rin].first-=l,len-=2*l;
        if(a[lin].first==0)lin++;
        if(a[rin].first==0)rin--;
    }
    cout<<cnt;
    return 0;
}



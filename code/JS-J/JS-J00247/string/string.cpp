#include <bits/stdc++.h>
#define N 200100
#define ll long long
using namespace std;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n,nowl=a[1],nowr=a[n];
    ll ans=0;
    while(l<r){
        int delta=min(nowl,nowr);
        if(c[l]!=c[r])
            ans+=delta;
        nowl-=delta,nowr-=delta;
        if(!nowl)
            l++,nowl=a[l];
        if(!nowr)
            r--,nowr=a[r];
    }
    cout<<ans;
    return 0;
}

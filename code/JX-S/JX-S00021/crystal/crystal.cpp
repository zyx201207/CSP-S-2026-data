#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],t[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k,p=1,maxx=-1;cin>>n>>m;k=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
        t[i]=a[i+1]-a[i];
    }
    t[n]=m+1;
    for(int i=1;i<=n;i++){
        if(t[i]*p<=k){
            k-=t[i]*p;
            p++;
        }else{
            maxx=max(maxx,p);
            k=m;p=1;
        }
    }
    cout<<maxx;
return 0;
}

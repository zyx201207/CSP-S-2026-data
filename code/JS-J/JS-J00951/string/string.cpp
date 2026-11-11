#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+5;
int n;
int a[maxn];
char c[maxn];
ll ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i]>>c[i];
    int p1=0,p2=n-1,v1=a[0],v2=a[n-1];
    while(p1<p2){
        int x=min(v1,v2);
        v1-=x,v2-=x;
        if(c[p1]!=c[p2]) ans+=x;
        if(v1==0) v1=a[++p1];
        if(v2==0) v2=a[--p2];
    }
    cout<<ans<<'\n';
    return 0;
}
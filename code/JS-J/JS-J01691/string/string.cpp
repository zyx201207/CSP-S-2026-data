#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
char c[N];
int s[N];
int n;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>c[i];
    for (int i=1;i<=n;++i)
        s[i]=s[i-1]+a[i];
    int l=1,r=s[n],lb=1,rb=n;
    char lc=c[1],rc=c[n];
    int ans=0;
    while(l<r){
        lc=c[lb];
        rc=c[rb];
        int b=min(s[lb]-l+1,r-s[rb-1]);
        // cerr<<b<<" "<<lb<<" "<<rb<<endl;
        // if(l==1&&r==s[n]) cerr<<b<<"\n";
        if(lc!=rc) ans+=b;
        if(b==s[lb]-l+1) ++lb;
        if(b==r-s[rb-1]) --rb;
        l+=b;
        r-=b;
    }
    cout<<ans;
    return 0;
}
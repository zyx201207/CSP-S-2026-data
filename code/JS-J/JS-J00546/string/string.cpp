#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int n;
int a[MAXN];
char c[MAXN];
char query(int x){
    int t=lower_bound(a+1,a+n+1,x)-a;
    return c[t];
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        a[i]+=a[i-1];
    }
    int l,r;
    if(a[n]&1) l=r=a[n]/2+1;
    else{l=a[n]/2;r=a[n]/2+1;}
    int ans=0;
    while(l>0){
        if(query(l)!=query(r)) ans++;
        l--;r++;
    }
    cout<<ans;
    return 0;
}

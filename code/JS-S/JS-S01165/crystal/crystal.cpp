#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n;
ll m,a[N],s[N];
ll check(int x){
    ll delta=(1ll)*a[x]*x-s[x];
}
int main(){
    freopen("crystal","r",stdin);
    freopen("crystal","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    sort(a+1,a+n+1);
    int l=1,r=n+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)<=m){
            if(l==mid) break;
            l=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%d\n",l);
    return 0;
}

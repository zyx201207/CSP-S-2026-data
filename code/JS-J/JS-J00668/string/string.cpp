#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

const int N=2e5+5;

ll a[N]; char b[N];
vector<ll> v;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char s[5];
        scanf("%lld%s",&a[i],s);
        b[i]=s[0];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n && a[i]<=a[n]/2;i++) v.push_back(a[i]);
    for(int i=n;i>0 && a[n]-a[i-1]<=a[n]/2;i--) v.push_back(a[n]-a[i-1]);
    v.push_back(0);
    v.push_back(a[n]/2);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ll ans=0;
    for(ll i=1;i<v.size();i++){
        int p=lower_bound(a+1,a+1+n,v[i])-a;
        int q=lower_bound(a+1,a+1+n,a[n]-v[i]+1)-a;
        if(b[p]!=b[q]) ans+=v[i]-v[i-1];
    }
    printf("%lld\n",ans);
    return 0;
}

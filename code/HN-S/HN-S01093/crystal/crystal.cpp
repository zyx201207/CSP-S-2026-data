#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define pb push_back
#define v(x) vector<x>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const int N=500010;
int n,m;
ll a[N],s[N];
int mx;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=0,r=i-1,mid,ans=i-1;
        while(l<=r){
            mid=(l+r)/2;
            if(a[i]*(i-mid)-(s[i]-s[mid])<=m) ans=mid,r=mid-1;
            else l=mid+1;
        }
        mx=max(mx,i-ans);
    }
    cout<<mx;
    return 0;
}
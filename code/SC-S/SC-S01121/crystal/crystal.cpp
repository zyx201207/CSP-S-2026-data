#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],s[N],maxx;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        long long l=1,r=i,ans;
        while(l<=r){
            long long mid=(l+r)>>1;
            if((i-mid+1ll)*a[i]-(s[i]-s[mid-1])<=m) ans=i-mid+1,r=mid-1;
            else l=mid+1;
        }
        maxx=max(maxx,ans);
    }
    cout << maxx;
    return 0;
}
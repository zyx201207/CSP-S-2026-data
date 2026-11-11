#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,cnt,mx;
int n;
const int N=500005;
ll a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool f=1;
    for (int i=2;i<=n;i++){
        s[i]=a[i]-a[i-1];
        if (s[i]!=s[i-1])f=0;
    }
    for (int j=2;j<=n;j++){
        ll t=m;
        cnt=1;
        for (int i=j;i<=n;i++){
            if (cnt*s[i]>t)break;
            t-=cnt*s[i];
            cnt++;
        }
        mx=max(mx,cnt);
        if (f)break;
    }
    cout<<mx;
    return 0;
}

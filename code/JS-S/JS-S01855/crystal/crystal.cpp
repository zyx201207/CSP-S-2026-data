#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n,m;
ll a[500005],b[500005],c[500005];
void solve_eq(){
    ll sum=0;
    int cnt=1;
    for (int i=1;i<=n;i++){
        sum+=i;
        if (sum>m){
            break;
        }
        cnt++;
    }
    cout << cnt << endl;
}
void solve_eqd(ll d){
    ll cnt=0;
    ll l=1,r=n,mid;
    while (l<=r){
        mid=(l+r)/2;
        if ((1+mid)*mid/2*d<=m){
            cnt=mid;
            l=mid+1;
        }else {
            r=mid-1;
        }
    }
    cout << cnt << endl;
}
ll calc(ll pilot,int pos){
    ll cost=0;
    for (int i=pos-1;i>=1;i--){
        cost+=pilot-b[i];
        if (cost>m) break;
        b[i]=pilot;
    }
    ll res=0;
    for (int i=1;i<=n;i++){
        if (b[i]==pilot) res++;
    }
    return res;
}
void solve_1e4(){
    ll ans=0,tmp=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            b[j]=a[j];
        }
        tmp=calc(a[i],i);
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}
int check(int pilot){
    ll cost=0;
    int cnt=0;
    for (int i=pilot-1;i>=1;i--){
        cost+=a[pilot]-a[i];
        if (cost>m) break;
        cnt++;
    }
    for (int i=pilot+1;i<=n;i++){
        if (a[i]==pilot) cnt++;
    }
    return cnt;
}

int main (){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    bool flag=true,isallzero=true,eqself=true;
    for (int i=1;i<=n;i++){
        eqself&=(a[i]==i);
    }
    if (eqself){
        solve_eq();
        return 0;
    }
    for (int i=2;i<n;i++){
        isallzero&=(c[i]==0);
        flag&=(c[i]==c[i+1]);
    }
    if (isallzero){
        cout << n << endl;
        return 0;
    }
    if (flag){
        solve_eqd(c[2]);
        return 0;
    }else if (n<=1e4){
        solve_1e4();
        return 0;
    }else {
        int ans=0;
        int l=1,r=n,mid;
        while (l<=r){
            mid=(l+r)/2;
            int tmp=check(mid);
            if (ans<tmp){
                l=mid+1;
                ans=tmp;
            }else {
                r=mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(a,b) for(int i=a; i<=b; i++)
#define forj(a,b) for(int j=a; j<=b; j++)
const int MAXN=500005;
ll n,m;
ll a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    fori(1,n){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=1;
    ll cnt=1, sum=0, ans=0;
    while(r<n){
        r++;
        sum+=(a[r]-a[r-1])*cnt;
        cnt++;
        while(sum>m){
            l++;
            sum-=a[r]-a[l-1];
            cnt--;
        }
        ans=max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}
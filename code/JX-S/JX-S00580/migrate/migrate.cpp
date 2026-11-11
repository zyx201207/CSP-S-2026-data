#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T,typename T2 = T> T updl(T &a,T2 b){return (a>b)?(a = b):b;}
template<typename T,typename T2 = T> T updg(T &a,T2 b){return (a<b)?(a = b):b;}
int qmi(int a,int k,int p){
    int res = (a%=p);
    while(k){
        if(k&1) res = 1LL*res*a%p;
        a = 1LL*a*a%p;
        k>>=1;
    }
    return res;
}
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
int n,d;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,_T = 1;
    cin >> c >> _T;
    while(_T--){
        cin >> n >> d;
        vector<int> a(n+5),cnt1(n+5),cnt2(n+5),precnt1(n+5),sufcnt2(n+5),b(n+5);
        for(int i = 1;i<=n;i++) cin >> a[i];
        a[0] = -6'000'000'000'000'000'000LL,a[n+1] = a[n+2] = 6'000'000'000'000'000'000LL;
        int ans = 0;
        {
            int pl = 1,pr = 1,l = 1,sl = 1;
            for(int i = 1;i<=n;i++){
                while(sl<i&&a[sl]+d<a[i+1]) sl++;
                while(l<i&&a[l]+d<a[i]) l++;
                while(pl<i&&a[pl]+d<a[l+1]) pl++;
                while(pr<i&&a[pr]+d<a[l+2]) pr++;
                cnt1[i] = precnt1[sl-1]-precnt1[l-1]+1;
                ans+=(i-l>=2&&pr>pl&&a[l+1]+d>=a[i+1])*(pr-pl+(a[pl-1]+d<a[l])*(cnt1[pl]-1));
                if(i-l>=2&&pr>pl&&a[l+1]+d<a[i+1]) b[i]+=(pr-pl+(a[pl-1]+d<a[l])*(cnt1[pl]-1));
                precnt1[i] = precnt1[i-1]+cnt1[i];
            }
        }
        {
            int r = n,sr = n;
            for(int i = n;i>=1;i--){
                while(sr>i&&a[i-1]+d<a[sr]) sr--;
                while(r>i&&a[i]+d<a[r]) r--;
                cnt2[i] = sufcnt2[sr+1]-sufcnt2[r+1]+1;
                ans+=(a[cnt2[i])*b[i];
                sufcnt2[i] = sufcnt2[i+1]+cnt2[i];
            }
        }
        cout << ans << '\n';
    }
}

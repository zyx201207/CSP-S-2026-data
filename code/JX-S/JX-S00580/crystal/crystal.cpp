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
int n,m,a[500005];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);//cha yi dian jiao cheng crystal4 le, hai hao gai le QAQ
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while(_T--){
        cin >> n >> m;
        for(int i = 1;i<=n;i++) cin >> a[i];
        sort(a+1,a+1+n);
        int now = m,l = 1,ans = 0;
        for(int r = 1;r<=n;r++){
            now-=(r-l)*(a[r]-a[r-1]);
            while(now<0) now+=(a[r]-a[l++]);
            updg(ans,r-l+1);
        }
        cout << ans << '\n';
    }
}


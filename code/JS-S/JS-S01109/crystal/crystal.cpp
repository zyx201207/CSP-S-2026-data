#include <bits/stdc++.h>
#define qi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define MP(a,b) make_pair(a,b)
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
const int N = 5e5+3;
int n,m;
int ans=0;
int a[N];
signed main(){
    qi;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int cnt=0;
    int j=1;
    ans=1;
    for(int i=2;i<=n;i++){
        cnt+=(i-j)*(a[i]-a[i-1]);
        while(cnt>m){
            cnt-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout << ans << endl;
    return 0;
}

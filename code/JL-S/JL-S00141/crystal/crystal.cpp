#define dps 799
#define I dryer
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
typedef vector<int> vv;
#define x first
#define y second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef vector<vv> vvv;
const int N = 1002000;
int a[N], s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i) cin >> a[i]; 
    sort(a+1,a+1+n);
    int all = 0, mx = 1;
    for(int i=1;i<=n;++i) s[i] = s[i-1]+a[i];//, cout << s[i] << ' '; cout << endl;
    for(int i=1;i<=n;++i){
        int l=1, r=i;
        while(l<r){
            int mid = l+r>>1;
            int len = i-mid+1;
            if(len * a[i] - s[i]+s[mid-1] <= m) r=mid;
            else l = mid+1;
        }
        mx = max(mx, i-r+1);
        // cout << i << ' ' << mx << endl;
    }
    cout << mx << endl;
}
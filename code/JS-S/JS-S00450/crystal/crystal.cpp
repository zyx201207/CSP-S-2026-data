#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
const ll maxn=5e5;
const int INF=0x3f3f3f3f;
ll n,m;
ll a[maxn],d[maxn];
int ans;
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        d[i]=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    ll cnt=a[0];
    int len=1;
    for(int i=1;i<n;i++){
        cnt+=len*(a[i]-a[i-1]);
        if(cnt>m){
            while(cnt>m){
                cnt-=a[i]-a[i-len];
                len--;
            }
        }
        ans=max(len,ans);
    }
    cout << ans;
}

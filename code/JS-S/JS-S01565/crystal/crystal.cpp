#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=0;
    int ans=1;
    int num=0;
    int l=1;
    for(int i=2;i<=n;i++){
        if(cnt+(i-l)*(a[i]-a[i-1])<=m){
            cnt+=(i-l)*(a[i]-a[i-1]);
            ans++;
        }else{
            i--;
            cnt-=(a[i]-a[l]);
            ans--;
            l++;
        }
        num=max(num,ans);
    }
    cout<<num<<endl;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}
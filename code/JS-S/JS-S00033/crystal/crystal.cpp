#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int f[N];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, cnt1=0, cnt2=0, t;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>f[i];
        if(f[i]==i) cnt1++;
        if(i==2){t=f[i]-f[i-1];}
        if(f[i]-f[i-1]==t) cnt2++;
    }
    if(cnt1==n){
        int ans=1;
        while(ans*(ans-1)/2<m){
            ans++;
        }
        if(ans*(ans-1)/2>m) ans--;
        cout<<min(ans, n);
        return 0;
    }
    if(cnt2==n-1){
        int ans=1;
        while(t*ans*(ans-1)/2<m){
            ans++;
        }
        if(t*ans*(ans-1)/2>m) ans--;
        cout<<min(ans, n);
        return 0;
    }
    sort(f+1, f+n+1);
    int ans=0;
    for(int i=2; i<=n; i++){
        int j=i-1, num=f[i]-f[j];
        while(num<m&&j>1){
            j--;
            num+=f[i]-f[j];
        }
        ans=max(ans, (num==m)?i-j+1:i-j);
    }
    cout<<ans;

    return 0;
}

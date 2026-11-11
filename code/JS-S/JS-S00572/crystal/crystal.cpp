#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> a(n+1);
void solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans=0;
    int cnt=0;
    int temp=0;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i]>=a[j]){
                temp+=a[i]-a[j];
                if(temp<=m) cnt++;
            }
            if(a[i]<a[j]) break;
        }
        ans=max(ans, cnt);
        cnt=0;
        temp=0;
    }
    cout<<ans;
    return;
}

signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","W",stdout);

    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

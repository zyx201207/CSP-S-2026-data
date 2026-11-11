#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pi pair<int,int>
const int N=2e5+5;
int n,m;
int a[N];
int t[35];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=31;j++){
            if( (a[i]&(1ll<<j)) == (1ll<<j) ){
                t[j]++;
            }
        }
    }
    int ans=0;
    bool f=0;
    for(int j=31;j>=0;j--){
        if(f==0&&t[j]>=m){
            ans=ans|(1ll<<j);
            f=1;
        }
        else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if( (a[i]&(1ll<<j))==(1ll<<j) && (a[i]&ans)==ans ){
                    cnt++;
                }
            }
            if( cnt>=m) {
                ans=ans|(1ll<<j);
            }
        }
    }
    cout<<ans;
    return 0;
}

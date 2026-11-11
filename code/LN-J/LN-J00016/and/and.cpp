#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int a[N];
void init(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
}
signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,maxa=-1;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<(1<<n);i++){
        int cnt=0,ans=-1;
        for(int j=0;j<n;j++){
            if(i>>j&1){
                cnt++;
                if(ans==-1) ans=a[j];
                else ans&=a[j];
            }
        }
        if(cnt==m){
            maxa=max(maxa,ans);
        }
    }
    cout << maxa;
    return 0;
}

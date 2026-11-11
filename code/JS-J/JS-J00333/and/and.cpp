#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200055;
int n,m;
bool b[N];
ll a[N],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=30;i>=0;i--){
        ll chk=(1<<i);
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(b[j])continue;
            if(a[j]&chk)cnt++;
        }
        if(cnt>=m){
            ans=ans|chk;
            for(int j=1;j<=n;j++){
                if(!(a[j]&chk))b[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}

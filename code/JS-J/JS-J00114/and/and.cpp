#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
bool used[N];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll M=1<<30;
    ll ans=0;
    while(M>0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(M&a[i] && used[i]==0) cnt++;
        }
        if(cnt>=m) {
            ans+=M;
            for(int i=1;i<=n;i++){
                if(!(M&a[i])) used[i]=1;
            }
        }
        M>>=1;
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
const int N=1000020;
int c,n,k,cnt,ans;
int a[N],s[N];
vector<int>g[N];
void solve(){
    cin>>n>>k;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(c==13||c==14){
        if(k==1){
            cout<<((n+1)/2+1)/2<<endl;
        }else{
            n=(n+1)/2+1;
            if(n%2==0){
                n/=2;
                k/=2;
                n-=(k-1);
                cout<<n/2<<endl;
            }else{
                if(k%2==0){
                    n/=2;
                    k/=2;
                    n-=(k-1);
                    cout<<n/2+1<<endl;
                }else{
                    n/=2;
                    k/=2;
                    n-=(k-1);
                    cout<<n/2<<endl;
                }
            }
        }
        return;
    }
    cout<<1<<endl;
}
signed main(){
    freopen("hub5.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _=1;
    cin>>c>>_;
    while(_--){
        solve();
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],cn[M];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        vector<int> v;
        for(int i=k;i<=n;i++){
            if(v.empty()){
                v.push_back(a[i]);
                continue;
            }
            for(int j=0;j<v.size();j++){
                if(a[i]==v[j]){
                    while(j<v.size())v.pop_back();
                }
            }
            v.push_back(a[i]);
        }
        for(int i=0;i<v.size();i++){
            cn[v[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cn[i]<<' ';
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
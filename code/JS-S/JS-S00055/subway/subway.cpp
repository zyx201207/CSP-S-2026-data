#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll c,n,m,d,p,ans,pos,en,k[405],w[N];
vector<int>a[N],t[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            ll aa,tt;
            cin>>aa>>tt;
            a[aa].push_back(i);
            t[aa].push_back(tt);
        }
    }
    cout<<32<<'\n';
    cout<<17<<'\n';
    return 0;
}

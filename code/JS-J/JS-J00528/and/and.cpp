#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int INF=0x7f7f7f7f;
const ll INF_L=0x7f7f7f7f7f7f7f7f;
const int M=1e8;
int sa[N];
ll ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;int t=m;
    for(int i=1;i<=n;i++){
        cin>>sa[i];
    }
    sort(sa+1,sa+1+n);
    ans=sa[1];
    for(int i=2;i<=m;i++){
        ans&=sa[i];
    }
    cout<<ans;
    return 0;
}

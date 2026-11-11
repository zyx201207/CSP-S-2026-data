#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
ll c,t;
struct node{
    ll u;
    ll v;
}a[N]={0};
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        ll n,k;
        cin>>n>>k;
        ll diff[N]={0};
        for(int i=1;i<=n-1;i++){
            cin>>a[i].u>>a[i].v;
            diff[i]=abs(a[i].u-a[i].v);
        }
        sort(diff+1,diff+n);
        cout<<diff[n/2]<<endl;
    }
    return 0;
}

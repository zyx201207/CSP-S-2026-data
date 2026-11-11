#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const int M=3e5+5;
ll n,m,a[N],ans[M],id[M],f;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        id[a[i]]=max(id[a[i]],i);
        if(a[i]>a[i-1])f=1;
    }
    for(ll i=1;i<=n;i++){
        if(f==0){
            for(ll j=1;j<=a[i];j++){
                ans[j]++;
            }
        }
        for(ll j=i;j<=n;j++){
            ans[a[j]]++;
            j=id[a[j]];
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

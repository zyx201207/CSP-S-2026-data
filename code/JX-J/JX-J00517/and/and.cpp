#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,m,a[N],cnt;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ll mx=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
    }else{
        for(int i=1;i<=n;i++) mx=max(mx,a[i]);
    }
    cout<<mx;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int n,m,a[maxn];
int f[maxn];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            f[j]=max(f[j],f[j-1]&a[i]);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}

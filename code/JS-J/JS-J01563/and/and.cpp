#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int f[200005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    f[0]=2147483647;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            f[j]=max(f[j],(f[j-1]&a[i]));
        }
    }
    cout<<f[m];
    return 0;
}

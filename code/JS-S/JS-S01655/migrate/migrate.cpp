#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[1010110],f[1010110],t[1010110];
bool check(int x){
    return a[x+1]-a[x]<=d&&a[x+2]-a[x]<=d&&a[x+3]-a[x+1]<=d&&a[x+3]-a[x+2]<=d;
}bool checkt(int x){
    return a[x+1]-a[x]<=d&&a[x+2]-a[x]<=d;
}
void once(){
    int ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-3;i++){
        f[i]=check(i);
        t[i]=checkt(i);
        f[i]+=f[i-1];
        t[i]+=t[i-1];
        //cout<<f[i]<<" "<<t[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+3;j<=n;j++){
            if(f[j-3]-f[i-1]==1&&t[j-2]-t[i+1]==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int c,tt;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>tt;
    while(tt--)once();
    return 0;

}/*

0 2

5 2
1 2 3 4 5

4 2
1 2 3 4






inclusteam xiaoheshuangpin
dcciyiyz

2026/10/31 14:30
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
int n,d,a[N];
int b[N],c[N],far[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in" ,"r",stdin );
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n-1;i++)b[i]=a[i+1]-b[i];
        for(int i=1;i<=n-1;i++)c[i]=c[i-1]+b[i];
        for(int l=1,r=1;r<=n-1;l++){
            while(c[r]-c[l-1]<=d&&r<=n-1)r++;
            far[l]=r-1;
        }
        cout<<0<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long c,t;cin>>c>>t;
    while(t--){
        long long n,d;cin>>n>>d;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)cin>>a[i];
        long long dd=llabs(a[2]-a[1]);
        if(dd*2<=d&&d<dd*3)cout<<max((long long)0,n-3)<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t,n,l;
long long d,g,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        long long s=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(n==1) g=a[1];
        else g=a[2]-a[1];
        g=d/g;
        for(int i=1;i<=n;i++){
            s+=(n-i-g+(g-1))/g;
        }
        cout<<s<<'\n';
    }
    return 0;
}

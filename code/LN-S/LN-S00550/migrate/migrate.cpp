#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int m=a[2]-a[1];
        m=d/m;
        int to=1+m+1;
        int ans=n-to+1;
        cout<<ans<<endl;
    }
    return 0;
}

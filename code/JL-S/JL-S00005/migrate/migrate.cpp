#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a[2000010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int csdbh;
    cin>>csdbh>>t;
    while(t--){
        memset(a,0,sizeof(a));
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(a[i]+2*d-1==a[j])ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrare.out","w",stdout);
    cin>>c>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i-j>=3&&(i-j)%2==1&&a[j+1]-a[j]<=m) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[2000005],f[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while (t--)
    {
        int ans=0;
        memset(f,0,sizeof(f));
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            a[i]=a[i]+d;
            for(int j=i+1;j<=n&&a[i]>=a[j];j++){
                f[j]++;
                }
        }
        for(int i=1;i<=n;i++)
            if(f[i]==2)
                ans++;
        cout<<ans-1<<'\n';
    }
    return 0;
}
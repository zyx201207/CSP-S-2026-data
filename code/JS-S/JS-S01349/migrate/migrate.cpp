#include <bits/stdc++.h>
#define maxn 2000001
using namespace std;
long long t,ans,c,a[maxn],f[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) f[i]=1;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;a[j]-d<=a[i]&&j<=n;j++) f[j]+=f[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;a[j]-d<=a[i]&&j<=n;j++) if(f[j]-f[i]==2) ans++;
        }
        cout<<ans;
    }
    return 0;
}

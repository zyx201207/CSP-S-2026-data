#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[10000005],sum[10000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        bool flag;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            if(i==2){
                int f=a[2]-a[1];
            }
            if(i>=3&&a[i]-a[i-1]!=f)
            {
                flag=false;
            }
        }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(a[i]-a[j]<=f||a[i]-a[j]>3*f)
                    {
                        break;
                    }
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}

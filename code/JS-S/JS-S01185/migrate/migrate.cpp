#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int main()
{   freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int aa=1;aa<=t;aa++){
        memset(a,0,sizeof(a));
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n-1;i++){

            for(int j=i+2;j<=n;j++){
                    int sum=0;
                if(a[j]-a[i]<=d) continue;
                for(int k=i+1;k<j;k++){
                    if(a[k]-a[i]<=d&&a[j]-a[k]<=d) {sum++;}
                }
            if(sum==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

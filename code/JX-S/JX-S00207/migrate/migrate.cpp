#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2145140],f[2145140],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(d>=a[n]-a[1]){
            cout<<0<<endl;
            continue;
        }
        for(int i=2,j=1;i<=n;i++){
            while(a[i]-a[j]>d){
                f[j]=i-1;
                j++;
            }
            if(i==n){
                for(;j<=n;j++){
                    f[j]=n;
                }
            }
        }
        for(int i=1;i<n;i++){
            int num;
            for(int j=f[i]+1;j<=n;j++){
                if(a[j]-a[f[i]-1]>d){
                    num=j-1;
                }
                else if(j==n) num=j;
            }
            ans+=(num-f[i]);
        }
        if(ans<0){
            cout<<0<<endl;
        }
        else cout<<ans<<endl;
    }
    return 0;
}
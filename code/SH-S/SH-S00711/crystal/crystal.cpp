#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans=1;
int a[500005];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            int k=1,h=m;
            for(int j=i-1;j>=1;j--){
                if(h>=a[i]-a[j]){
                    h-=a[i];
                    h+=a[j];
                    k++;
                }
                else{
                    break;
                }
            }
            ans=max(ans,k);
        }
        cout<<ans<<endl;
    }
    else{
        int k=n-1,h=m,fl=1;
        for(int i=n;i>=ans;i--){
            if(k>=i){
                k=i-1;
                h=m;
                fl=1;
            }
            if(fl==0){
                h=h+(a[i+1]-a[i])*(i-k);
            }
            fl=0;
            for(int j=k;j>=1;j--){
                if(h>=a[i]-a[j]){
                    h-=a[i];
                    h+=a[j];
                }
                else{
                    k=j;
                    break;
                }
            }
            ans=max(ans,i-k);
            if(a[i]-a[k]<=h){
                ans=max(ans,i-k+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
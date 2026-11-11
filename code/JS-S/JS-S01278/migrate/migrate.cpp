#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t,n,ans,d,s;
ll a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n-2;i++){
            s=0;
            if(a[i+1]-a[i]<=d){
                bool f=0;
                if(a[i+2]-a[i+1]<=d&&a[i+2]-a[i]<=d){
                    f=1;
                    s=1;
                    for(int j=i+3;j<=n;i++){
                        if(a[j]-a[j-1]>d) break;
                        if(a[j]-a[j-2]<=d) break;
                        s++;
                    }
                    ans+=s;
                }
                if(f==0){
                    for(int j=i+3;j<=n;j++){
                        if(a[j]-a[j-1]>d) break;
                        if(a[j]-a[j-3]<=d) break;
                        if(a[j]-a[j-2]<=d){
                            f=1;
                            break;
                        }
                        s++;
                    }
                    ll su=1;
                    for(int i=i+s+4;i<=n;i++){
                        if(a[i]-a[i-1]>d) break;
                        if(a[i]-a[i-2]<=d) break;
                        su++;
                    }
                    ans+=su;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

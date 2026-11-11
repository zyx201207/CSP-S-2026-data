#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005];
long long cnt=0,mnl=0x3f3f;
void fin(long long x,long long le,int ed){
    if(x==ed){
        if(le==mnl) cnt++;
        else if(le<mnl){
            cnt=0;
            mnl=le;
        }
        return;
    }
    for(int i=1;i<=d;i++){
        if(x+i>n) break;
        fin(x+i,le+(a[x+i]-a[x]),ed);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                fin(i,0,j);
                if(cnt==2){
           //         cout<<a[i]<<" ";
                    ans++;
                }
                mnl=0x3f3f;
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

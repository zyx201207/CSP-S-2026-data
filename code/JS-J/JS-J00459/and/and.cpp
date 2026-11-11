#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],w[31];
bool areac[N],reac[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    w[0]=1;
    for(int i=1;i<=30;i++)w[i]=w[i-1]*2;
    int ans=0;
    bool ok=0;
    for(int j=30;j>=0;j--){
        int cntr=0;
        if(ok==0){
            for(int i=1;i<=n;i++){
                if(a[i]>=w[j]){
                    reac[i]=1;
                    cntr++;
                    a[i]-=w[j];
                }
            }
            if(cntr>=m){
                for(int i=1;i<=n;i++){
                    areac[i]=reac[i];
                }
                ans+=w[j];
                ok=1;
            }
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]>=w[j]&&areac[i]==1){
                    reac[i]=1;
                    cntr++;
                    a[i]-=w[j];
                }
            }
            if(cntr>=m){
                for(int i=1;i<=n;i++){
                    areac[i]=reac[i];
                }
                ans+=w[j];
            }
        }
        for(int i=1;i<=n;i++)reac[i]=0;
        cntr=0;
    }
    cout<<ans;
    return 0;
}

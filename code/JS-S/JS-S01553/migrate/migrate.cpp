#include<bits/stdc++.h>
using namespace std;
long long w[100005];
long long y[100005];
long long b[100005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long ans=0;
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
                long long o=1;
            for(int j=1;j<i;j++){
                o=0;
                if(w[i]-w[j]<=d&&(b[j]+1==b[i]||b[i]==0)){
                    y[i]+=y[j];
                    b[i]=b[j]+1;
                }
            }
        if(o==1){
            y[i]=1;
        }
        if(y[i]==2){
            ans++;
        }

    }
 for(int i=1;i<=n;i++){
            y[i]=0;
            b[i]=0;
        }
    cout<<ans<<endl;
    }
    return 0;
}

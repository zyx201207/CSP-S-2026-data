#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d,x[2000005],ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(x[n]-x[1]<=d){
            cout<<"0"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d&&(j-i>=1||j-i==0)) continue;
                else if(x[j]-x[i]<=d&&j-i==1) ans++;
                else{
                    if(j-i+1==4) ans++;
                    else continue;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

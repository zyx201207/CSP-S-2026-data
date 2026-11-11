#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,x[N];
int main(){
    freopen("r",migrate.in);
    freopen("w",migrate.out);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            x[i]=abs(x[i]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(i!=j && x[i]+x[j]==x[n]) ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}

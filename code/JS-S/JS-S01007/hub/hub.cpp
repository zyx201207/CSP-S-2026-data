#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[1000005],v[1000005],m,f;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        m=(n-1)/2;
        if(k>=2){
            for(int i=1;i<=m+1;i++){
                if((m-2*i+2-k)/2+1<=i){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
